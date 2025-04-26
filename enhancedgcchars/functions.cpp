#include "pch.h"

extern std::string sonicOption;
extern std::string shadowOption;
extern std::string amyOption;
extern std::string metalOption;

extern std::string tailsOption;
extern std::string eggmechOption;
extern std::string chaoOption;
extern std::string darkchaoOption;

extern std::string knuxOption;
extern std::string rougeOption;
extern std::string tikalOption;
extern std::string chaosOption;

extern std::string milesOption;
extern std::string eggOption;


extern std::string sonicaltOption;
extern std::string shadowaltOption;
extern std::string knuxaltOption;
extern std::string rougealtOption;
extern std::string eggaltOption;


extern std::string rougealtOption;
extern std::string tikalaltOption;


extern bool battleMenuOption;
extern bool kartRaceOption;


// Config checking function

bool isActive(std::string input)
{
	if (input != "off")
	{
		return true;
	}
	return false;
}