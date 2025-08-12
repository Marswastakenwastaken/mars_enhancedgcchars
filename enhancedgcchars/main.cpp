#include "pch.h"

std::string pathGlobal;

HelperFunctions GlobalHelperFunctions;

HMODULE globaldll;

EGC_CONFIG mod_config =
{
	"default",
	"gc",
	"default",
	"gc",
	"default",
	false,
	"default",

	"default",
	"default",
	"gc",
	"default",
	"default",

	"default",
	"gc",
	"default",
	"gc",
	"default",
	"default",
	"default",
	"default",

	"default",
	"default",

	true,
	true
};

extern "C"
{
	__declspec(dllexport) void __cdecl 
		Init(const char* path, const HelperFunctions& helperFunctions)
	{

		GlobalHelperFunctions = helperFunctions;

		pathGlobal = path;

		HMODULE hmodule = GetModuleHandle(__TEXT("Data_DLL_orig"));
		auto DLCKarts = helperFunctions.Mods->find_by_dll(GetModuleHandle(L"kart-dlc.dll"));

		globaldll = hmodule;

		const
			IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		// Speed Configs

		mod_config.sonic = config->getString("speedchars", "sonic", "default");
		mod_config.shadow = config->getString("speedchars", "shadow", "default");
		mod_config.amy = config->getString("speedchars", "amy", "default");
		//mod_config.hammer = config->getBool("speedchars", "hammer", false);
		mod_config.metal = config->getString("speedchars", "metal", "default");

		// Mech Configs

		mod_config.mech_tails = config->getString("mechchars", "tailsmech", "default");
		mod_config.mech_eggman = config->getString("mechchars", "eggmech", "default");
		mod_config.chaowalker = config->getString("mechchars", "chao", "default");
		mod_config.darkwalker = config->getString("mechchars", "darkchao", "default");

		// Hunter Configs

		mod_config.knuckles = config->getString("hunterchars", "knuck", "default");
		mod_config.rouge = config->getString("hunterchars", "rouge", "default");
		mod_config.tikal = config->getString("hunterchars", "tikal", "default");
		mod_config.chaos = config->getString("hunterchars", "chaos", "default");

		// Mechless Configs

		mod_config.miles = config->getString("mechlesschars", "miles", "default");
		mod_config.eggman = config->getString("mechlesschars", "egg", "default");

		// Alt Configs

		mod_config.sonicalt = config->getString("speedchars", "sonicalt", "gc");
		mod_config.shadowalt = config->getString("speedchars", "shadowalt", "gc");
		mod_config.knucklesalt = config->getString("hunterchars", "knuckalt", "gc");
		mod_config.rougealt = config->getString("hunterchars", "rougealt", "gc");
		mod_config.eggman_alt = config->getString("mechchars", "eggalt", "gc");

		mod_config.rougeanm = config->getString("hunterchars", "rougeanim", "default");
		mod_config.tikalanm = config->getString("hunterchars", "tikalanim", "default");

		mod_config.menu = config->getBool("systemconfig", "battlemenu", true);
		mod_config.karts = config->getBool("systemconfig", "karts", true);

		delete config;

		
		PrintDebug("Initializing mod.");
		
		InitSonic();
		InitShadow();
		InitAmy();
		InitMetal();
		InitTails();
		InitEggman();
		InitChaoWalker();
		InitDarkChaoWalker();
		InitKnuckles();
		InitRouge();
		InitTikal();
		InitChaos0();
		InitBattleMenu();
		InitKarts();

		PrintDebug("Initialization done.");
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}
