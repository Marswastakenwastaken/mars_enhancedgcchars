#include "pch.h"

#define ReplaceMDL(a,b) helperFunctions.ReplaceFile("resource\\gd_PC\\" a ".prs", "resource\\gd_PC\\" b ".prs");
#define ReplacePAK(a,b) helperFunctions.ReplaceFile("resource\\gd_PC\\PRS\\" a ".pak", "resource\\gd_PC\\PRS\\" b ".pak");

std::string
sonicOption = "default";
std::string
shadowOption = "default";
std::string
amyOption = "default";
std::string
metalOption = "default";


std::string
tailsOption = "default";
std::string
eggmechOption = "default";
std::string
chaoOption = "default";
std::string
darkchaoOption = "default";

std::string
knuxOption = "default";
std::string
rougeOption = "default";
std::string
tikalOption = "default";
std::string
chaosOption = "default";

std::string
milesOption = "default";
std::string
eggOption = "default";

std::string
sonicaltOption = "default";
std::string
shadowaltOption = "default";
std::string
knuxaltOption = "default";
std::string
rougealtOption = "default";
std::string
eggaltOption = "default";

extern "C"
{
	// Optional.
	// This function runs code one time when the game starts up. Great for loading assets and setting things up.
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		
		// Speed Configs

		sonicOption = config->getString("speedchars", "sonic", "default");
		shadowOption = config->getString("speedchars", "shadow", "default");
		amyOption = config->getString("speedchars", "amy", "default");
		metalOption = config->getString("speedchars", "metal", "default");

		// Mech Configs

		tailsOption = config->getString("mechchars", "tailsmech", "default");
		eggmechOption = config->getString("mechchars", "eggmech", "default");
		chaoOption = config->getString("mechchars", "chao", "default");
		darkchaoOption = config->getString("mechchars", "darkchao", "default");

		// Hunter Configs

		knuxOption = config->getString("hunterchars", "knuck", "default");
		rougeOption = config->getString("hunterchars", "rouge", "default");
		tikalOption = config->getString("hunterchars", "tikal", "default");
		chaosOption = config->getString("hunterchars", "chaos", "default");

		// Mechless Configs

		milesOption = config->getString("speedchars", "miles", "default");
		eggOption = config->getString("speedchars", "egg", "default");

		// Alt Configs

		knuxaltOption = config->getString("hunterchars", "knuckalt", "gc");
		rougealtOption = config->getString("hunterchars", "rougealt", "gc");
		eggaltOption = config->getString("mechchars", "eggalt", "gc");

		delete config;

		PrintDebug("Initializing mod.");

		PrintDebug("Begin Sonic initialization.");
		if (sonicOption == "default") {
			ReplaceMDL("SONICMDL", "SONICMDL_EN");
			PrintDebug("Sonic model replaced with enhanced model.");
			ReplaceMDL("SSONICMDL", "SSONICMDL_EN");
			PrintDebug("Super Sonic model replaced with enhanced model.");
		}
		else if (sonicOption == "trialred") {
			ReplaceMDL("SONICMDL", "SONICMDL_TR");
			PrintDebug("Sonic model replaced with enhanced Trial shoes model.");
			ReplacePAK("SONICTEX", "SONICTEX_trial");
			PrintDebug("Sonic textures replaced with red soled Trial shoes textures.");
			ReplaceMDL("SSONICMDL", "SSONICMDL_TR");
			PrintDebug("Super Sonic model replaced with enhanced Trial shoes model.");
			ReplacePAK("SSONICTEX", "SSONICTEX_trial");
			PrintDebug("Super Sonic textures replaced with red soled Trial shoes textures.");
		}
		else if (sonicOption == "trialgray") {
			ReplaceMDL("SONICMDL", "SONICMDL_TR");
			PrintDebug("Sonic model replaced with enhanced Trial shoes model.");
			ReplacePAK("SONICTEX", "SONICTEX_trialgray");
			PrintDebug("Sonic textures replaced with gray soled Trial shoes textures.");
			ReplaceMDL("SSONICMDL", "SSONICMDL_TR");
			PrintDebug("Super Sonic model replaced with enhanced Trial shoes model.");
			ReplacePAK("SSONICTEX", "SSONICTEX_trialgray");
			PrintDebug("Super Sonic textures replaced with gray soled Trial shoes textures.");
		}
		else {
			PrintDebug("No replacements made.");
		}
		if (sonicOption != "off") {
			ReplaceMDL("SONIC1MDL", "SONIC1MDL_EN");
			PrintDebug("Racesuit Sonic model replaced with enhanced model.");
		}

		PrintDebug("Begin Shadow initialization.");
		if (shadowOption == "default") {
			ReplaceMDL("TERIOSMDL", "TERIOSMDL_EN");
			PrintDebug("Shadow model replaced with enhanced model.");
			ReplaceMDL("SSHADOWMDL", "SSHADOWMDL_EN");
			PrintDebug("Super Shadow model replaced with enhanced model.");
			ReplaceMDL("SHADOW1MDL", "SHADOW1MDL_EN");
			PrintDebug("Racesuit Shadow model replaced with enhanced model.");
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Amy initialization.");
		if (amyOption == "default") {
			ReplaceMDL("AMYMDL", "AMYMDL_EN");
			PrintDebug("Amy model replaced with enhanced model.");
		}
		else if (amyOption == "eyeliner") {
			ReplaceMDL("AMYMDL", "AMYMDL_EL");
			PrintDebug("Amy model replaced with eyeliner model.");
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Metal Sonic initialization.");
		if (shadowOption == "default") {
			ReplaceMDL("METALSONICMDL", "METALSONICMDL_EN");
			PrintDebug("Metal Sonic model replaced with enhanced model.");
		}
		else {
			PrintDebug("No replacements made.");
		}


		PrintDebug("Begin Cyclone initialization.");
		if (tailsOption == "default") {
			ReplaceMDL("TWALKMDL", "TWALKMDL_EN");
			PrintDebug("Cyclone model replaced with enhanced model.");
			ReplaceMDL("TWALK1MDL", "TWALK1MDL_EN");
			PrintDebug("Typhoon model replaced with enhanced model.");
			ReplacePAK("TWALK1TEX", "TWALK1TEX_en");
			PrintDebug("Typhoon textures replaced with enhanced textures.");
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Mechless Tails initialization.");
		if (milesOption == "default") {
			ReplaceMDL("MILESMDL", "MILESMDL_EN");
			PrintDebug("Tails model replaced with enhanced model.");
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Egg Walker initialization.");
		if (eggmechOption == "default") {
			ReplaceMDL("EWALKMDL", "EWALKMDL_EN");
			PrintDebug("Egg Walker model replaced with enhanced model.");

			if (eggaltOption == "gc") {
				ReplaceMDL("EWALK2MDL", "EWALK2MDL_EN");
				PrintDebug("Egg Tank model replaced with enhanced model.");
			}
			if (eggaltOption == "dc") {
				ReplaceMDL("EWALK2MDL", "EWALK1MDL_EN");
				PrintDebug("Egg Tank model replaced with Egg Camo model.");
				ReplacePAK("EWALK2TEX", "EWALK1TEX");
				PrintDebug("Egg Tank textures replaces with Egg Camo textures.");
			}
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Mechless Eggman initialization.");
		if (eggOption == "default") {
			ReplaceMDL("EGGMDL", "EGGMDL_EN");
			PrintDebug("Eggman model replaced with enhanced model.");
		}
		else {
			PrintDebug("No replacements made.");
		}


		PrintDebug("Begin Knuckles initialization.");
		if (knuxOption == "default") {
			ReplaceMDL("KNUCKMDL", "KNUCKMDL_EN");
			PrintDebug("Knuckles model replaced with enhanced model.");
			ReplaceMDL("BKNUCKMDL", "BKNUCKMDL_EN");
			PrintDebug("Knuckles alt model replaced with enhanced model.");
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Rouge initialization.");
		if (rougeOption == "default") {
			ReplaceMDL("ROUGEMDL", "ROUGEMDL_EN");
			PrintDebug("Rouge model replaced with enhanced model.");

			if (rougealtOption == "dc") {
				ReplaceMDL("BROUGEMDL", "BROUGEMDL_DC");
				PrintDebug("Rouge Alt model replaced with DC style model.");
				ReplacePAK("BROUGETEX", "BROUGETEX_dc");
				PrintDebug("Rouge Alt textures replaced with DC style textures.");
			}
			if (rougealtOption == "gc") {
				ReplaceMDL("BROUGEMDL", "BROUGEMDL_EN");
				PrintDebug("Rouge Alt model replaced with enhanced model.");
			}
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Tikal initialization.");
		if (tikalOption == "default") {
			ReplaceMDL("TICALMDL", "TICALMDL_EN");
			PrintDebug("Tikal model replaced with enhanced model.");
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Begin Chaos Zero initialization.");
		if (chaosOption == "default") {
			ReplaceMDL("CHAOS0MDL", "CHAOS0MDL_EN");
			PrintDebug("Chaos Zero model replaced with enhanced model.");
		}
		else {
			PrintDebug("No replacements made.");
		}

		PrintDebug("Initialization done.");
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}
