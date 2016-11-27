#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <sstream>

using namespace std;

void SomeStringWork()
{
	string Name{ "Holger" };
	string SurName{ "Kolb" };
	string FullName = Name + " " + SurName;
	cout << FullName << endl;
	cout << "len = " << FullName.length() << endl;

	string Other = "Elke Kolb";

	if (Other != FullName)
		cout << "Other != FullName\n";

	string Next = Other;
	if (Other == Next)
		cout << "Other == Next\n";
}

void StringFormatting()
{
	stringstream forFormat;

	forFormat << "hallo = " << setw(10) << setfill('0') << 42 << ends;
	string result = forFormat.str();

	cout << result << endl;
}

void UseRegularExpressions()
{
	string text = "19.25 Uhr:  Tennisstar Andy Murray äußerte sich via Twitter genervt über die \"negative Kampagne des 'Nein' - Lagers\". Der 27-Jährige, der zum Referendum bislang nicht eindeutig Stellung bezogen hatte, sprach von einem \"großen Tag für Schottland\" und beendete seinen Tweet mit einem Slogan der \"Ja\"-Kampagne: \"Lasst es uns tun!\" Die Botschaft des populären Sportlers wurde binnen weniger Stunden mehr als 12.000 Mal in Twitter weiterverbreitet.\
18.52 Uhr: In Großbritannien stiegen einige Investoren in der Hoffnung auf einen Verbleib Schottlands im Vereinigten Königreich wieder in den dortigen Aktienmarkt ein.In Umfragen lag das \"Nein\" - Lager knapp vorn.Das endgültige Ergebnis soll am Freitag \"zur Frühstückszeit\" bekanntgegeben werden.\
Der Londoner Auswahlindex FTSE gewann 0, 6 Prozent.Zu den Favoriten gehörten dabei schottische Unternehmen wie Royal Bank of Scotland(RBS) oder der Versicherer Standard Life, die sich um 0, 6 beziehungsweise 1, 5 Prozent verteuerten.Das britische Pfund setzte seinen Erholungskurs ebenfalls fort und kostete 1, 6367 Dollar.Zur europäischen Gemeinschaftswährung kletterte es sogar auf ein Zwei - Jahres - Hoch.Ein Euro fiel auf 0, 7854 Pfund.\
18.28 Uhr : Der englischen Zeitung „Mirror“ zufolge ist in einem Wahllokal in Glasgow eine 67 - Jährige festgenommen worden.Sie soll heute Mittag gegen ein Uhr eine andere Frau angegriffen haben.Morgen soll sie deswegen vor dem örtlichen Polizeigericht erscheinen.";

	smatch mr;
	regex rx("\\d+.\\d+ Uhr\\s*:");
	while (regex_search(text, mr, rx))
	{
		for (auto hit : mr)
			cout << hit << endl;
		text = mr.suffix();
	}
}

int main()
{
	SomeStringWork();
	StringFormatting();
	UseRegularExpressions();
}