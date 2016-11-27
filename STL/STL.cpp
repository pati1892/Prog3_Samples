#include <array>

#include "UseContainer.h"
#include "UseMap.h"

int main()
{
	UseContainer::BrowseFilesystem();
	
	UseMap messages;

	std::array<std::string, 3> list = {"Case2", "Case1", "Case3"};
	for (auto item : list)
		messages.SwitchWithMap(item);
}