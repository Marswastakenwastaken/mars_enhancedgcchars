#include "pch.h"

std::string pathGlobal;

HelperFunctions GlobalHelperFunctions;

HMODULE globaldll;

EGC_CONFIG_ENTRY config_list[] =
{
	{
		SONIC_MDL,
		"default",
		false
	},
	{
		SONIC_ALT,
		"gc",
		false
	},
	{
		SHADOW_MDL,
		"default",
		false
	},
	{
		SHADOW_ALT,
		"gc",
		false
	},
	{
		AMY_MDL,
		"default",
		false
	},
	{
		AMY_HMR,
		" ",
		false
	},
	{
		METAL_MDL,
		"default",
		false
	},


	{
		TWALK_MDL,
		"default",
		false
	},
	{
		EWALK_MDL,
		"default",
		false
	},
	{
		EWALK_ALT,
		"gc",
		false
	},

	{
		KNUX_MDL,
		"default",
		false
	},
	{
		KNUX_ALT,
		"gc",
		false
	},
	{
		ROUGE_MDL,
		"default",
		false
	},
	{
		ROUGE_ALT,
		"gc",
		false
	},
	{
		ROUGE_ANM,
		"default",
		false
	},
	{
		TIKAL_MDL,
		"default",
		false
	},
	{
		TIKAL_ANM,
		"default",
		false
	},
	{
		CHAOS_MDL,
		"default",
		false
	},

	{
		MILES_MDL,
		"default",
		false
	},
	{
		EGG_MDL,
		"default",
		false
	},

	{
		SYS_BATTLE,
		" ",
		false
	},
	{
		SYS_KART,
		" ",
		false
	},
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

		config_list[SONIC_MDL].val_string = config->getString("speedchars", "sonic", "default");
		config_list[SHADOW_MDL].val_string = config->getString("speedchars", "shadow", "default");
		config_list[AMY_MDL].val_string = config->getString("speedchars", "amy", "default");
		//config_list[AMY_HMR].val_bool = config->getBool("speedchars", "hammer", false);
		config_list[METAL_MDL].val_string = config->getString("speedchars", "metal", "default");

		// Mech Configs

		config_list[TWALK_MDL].val_string = config->getString("mechchars", "tailsmech", "default");
		config_list[EWALK_MDL].val_string = config->getString("mechchars", "eggmech", "default");
		//chaoOption = config->getString("mechchars", "chao", "default");
		//darkchaoOption = config->getString("mechchars", "darkchao", "default");

		// Hunter Configs

		config_list[KNUX_MDL].val_string = config->getString("hunterchars", "knuck", "default");
		config_list[ROUGE_MDL].val_string = config->getString("hunterchars", "rouge", "default");
		config_list[TIKAL_MDL].val_string = config->getString("hunterchars", "tikal", "default");
		config_list[CHAOS_MDL].val_string = config->getString("hunterchars", "chaos", "default");

		// Mechless Configs

		config_list[MILES_MDL].val_string = config->getString("mechlesschars", "miles", "default");
		config_list[EGG_MDL].val_string = config->getString("mechlesschars", "egg", "default");

		// Alt Configs

		config_list[SONIC_ALT].val_string = config->getString("speedchars", "sonicalt", "gc");
		config_list[SHADOW_ALT].val_string = config->getString("speedchars", "shadowalt", "gc");
		config_list[KNUX_ALT].val_string = config->getString("hunterchars", "knuckalt", "gc");
		config_list[ROUGE_ALT].val_string = config->getString("hunterchars", "rougealt", "gc");
		config_list[EWALK_ALT].val_string = config->getString("mechchars", "eggalt", "gc");

		config_list[ROUGE_ANM].val_string = config->getString("hunterchars", "rougeanim", "default");
		config_list[TIKAL_ANM].val_string = config->getString("hunterchars", "tikalanim", "default");

		config_list[SYS_BATTLE].val_bool = config->getBool("systemconfig", "battlemenu", true);
		config_list[SYS_KART].val_bool = config->getBool("systemconfig", "karts", true);

		delete config;

		
		PrintDebug("Initializing mod.");
		
		InitSonic();
		InitShadow();
		InitAmy();
		InitMetal();
		InitTails();
		InitEggman();
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
