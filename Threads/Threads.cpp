#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

mutex myLock; // Objekt für eine Synchronisation mit einzelnem Zugriff

void PrintThreadId(const char* Info)
{
	lock_guard<mutex> lock(myLock); // Synchronisation des folgenden Blockes 
	//myLock.lock(); // erfolgt bei Konstruktion

	// Ausgaben der Thread Info
	cout << Info << endl;
	cout << "current thread id=" << this_thread::get_id() << endl;

	// sleep für 0.5 Sekunden
	// Kontrolle abgeben, defensive Verwendung 
	chrono::milliseconds dura(500);
	this_thread::sleep_for(dura);

	//myLock.unlock(); // erfolgt bei Destruktion
}

void CreateAndUseThreads()
{
	// der Thread startet ohne zutun, kein start, suspend, resume oder ...
	// die Maschine und die Runtimebibliothek fällen die Entscheidung für den besten Start
	thread first([]() { PrintThreadId("first"); }),
		second([]() { PrintThreadId("second"); });

	this_thread::yield(); // abgeben an andere Threads geht schon

	// Ausgabe der aktuellen Thread Id mit Text
	PrintThreadId("CreateAndUseThreads");

	// warten auf das Ende der Threads, sonst gibt es Laufzeitprobleme
	first.join();
	second.join();
}

/******************************************************************************************************************/

void PrintInt(future<char*>& fut) {
	PrintThreadId(fut.get()); // lese Zugriff synchron und blockierend auf Daten mit future
}

void UseFuture()
{	
	promise<char*> promiseSet; // zum Setzen der Daten eines Objektes
	future<char*> futureGet = promiseSet.get_future(); // zum Lesen der Daten aus dem Promise in der Zukunft
	thread work(PrintInt, ref(futureGet)); // Thread erzeugen mit Methode und dem zugehörigen futur für das Lesen
	promiseSet.set_value("storeDataForFuture"); // setzen der Daten für den Thread

	work.join(); // warten auf das Ende
}

/******************************************************************************************************************/

void Accumulate(promise<int> &p)
{
	int sum = 0;
	for (int i = 0; i < 5; ++i)
		sum += i;
	p.set_value(sum); // Thread setzt sein Ergebnis im promise
}

void UsePromise()
{
	promise<int> p;
	future<int> f = p.get_future();
	thread t{ Accumulate, ref(p) }; 
	std::cout << "accumulate = " << f.get() << '\n'; // future ist geblockt bis promise sein Ergebnis setzt

	t.join(); 
}

/******************************************************************************************************************/

class Product
{
public:
	Product() {}
	~Product() {}
	std::string Payload;
};

void Producer(promise<Product> &p)
{
	Product prd;
	prd.Payload = "Product";
	cout << "produce = " << prd.Payload << endl;
	p.set_value(prd); // setzt die erzeugten Daten
}

void Consumer(future<Product> &f)
{
	auto prd = f.get(); // ließt die erzeugten Daten
	cout << "consume = " << prd.Payload << endl;
}

void Production()
{
	promise<Product> accessWr;
	future<Product> accessRd = accessWr.get_future();
	thread consumption(Consumer, ref(accessRd));
	thread production(Producer, ref(accessWr));

	production.join();
	consumption.join();
}

/******************************************************************************************************************/

string dataExchanged; // Daten für den synch. Austausch

mutex m; // exklusiver Zugriff
condition_variable cv; // Bedingung
// Signale für Bedingung
bool ready = false; 
bool processed = false;

void WorkerThread()
{
	unique_lock<mutex> lk(m);
	cv.wait(lk, [] { return ready; }); // warte aus ready = true

	// Ausgabe und Datenmanipulation
	cout << "Worker thread is processing data\n";
	dataExchanged += " after processing";

	// processed setzen
	processed = true;
	cout << "Worker thread signals data processing completed\n";

	// freigeben des locks vor Signal damit im wartenten Thread nicht sofort ein Block auftritt
	lk.unlock();
	cv.notify_one(); // Signal an wartenden schicken
}

void RunWithSignal()
{
	thread worker(WorkerThread); // Thread erzeugen

	dataExchanged = "Example data"; // Daten setzen

	// Daten gesetzt signalisieren
	{
		lock_guard<mutex> lk(m);
		ready = true;
		std::cout << "signals data ready for processing\n";
	}
	cv.notify_one(); // ab hier kann der Thread weiterlaufen

	// warten auf Signal vom Thread
	{
		unique_lock<mutex> lk(m);
		cv.wait(lk, [] { return processed; });
	}
	cout << "Back in RunWithSignal, data = " << dataExchanged << '\n';

	worker.join();
}

/******************************************************************************************************************/

void outThreadId()
{
	std::cout << "thread id=" << this_thread::get_id() << endl;
}

void UseAsync()
{
	outThreadId();
	auto forRun = [](auto i) {	
		outThreadId();
		return i * 2;
	};

	// maybe async or not
	auto result = std::async(forRun, // method to call
		11); // params for call
	std::cout << "result=" << result.get() << "\n";

	// sync 
	result = std::async(launch::deferred,
		forRun, // method to call
		12); // params for call
	std::cout << "result=" << result.get() << "\n";

	// async 
	result = std::async(launch::async,
		forRun, // method to call
		13); // params for call
	std::cout << "result=" << result.get() << "\n";
}

void main()
{
	CreateAndUseThreads();
	UseFuture();
	UsePromise();
	Production();
	RunWithSignal();
	UseAsync();
}