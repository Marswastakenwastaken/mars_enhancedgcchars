#include "pch.h"

#define ReplaceMDL(a,b) helperFunctions.ReplaceFile("resource\\gd_PC\\" a ".prs", "resource\\gd_PC\\" b ".prs");
#define ReplacePAK(a,b) helperFunctions.ReplaceFile("resource\\gd_PC\\PRS\\" a ".pak", "resource\\gd_PC\\PRS\\" b ".pak");
#define ReplaceFILE(a,b) helperFunctions.ReplaceFile("resource\\gd_PC\\" a, "resource\\gd_PC\\" b);


// This was salvaged from the DC Chars repo.
#define FindModel(file) new ModelInfo(std::string(path) + "\\Assets\\" file);
#define ReplaceSingleTex(gvm, gvr, folder, name, index, x, y) helperFunctions.ReplaceTexture(gvm, gvr, (std::string(path) + "\\Assets\\" folder "\\" name ".png").c_str(), index, x, y)

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
sonicaltOption = "gc";
std::string
shadowaltOption = "gc";
std::string
knuxaltOption = "gc";
std::string
rougealtOption = "gc";
std::string
eggaltOption = "gc";

std::string
rougeanmOption = "default";

bool
battleMenuOption = true;

extern "C"
{
	__declspec(dllexport) void __cdecl 
	Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HMODULE hmodule = GetModuleHandle(__TEXT("Data_DLL_orig"));

		const 
		IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		
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

		sonicaltOption = config->getString("speedchars", "sonicalt", "gc");
		shadowaltOption = config->getString("speedchars", "shadowalt", "gc");
		knuxaltOption = config->getString("hunterchars", "knuckalt", "gc");
		rougealtOption = config->getString("hunterchars", "rougealt", "gc");
		eggaltOption = config->getString("mechchars", "eggalt", "gc");

		rougeanmOption = config->getString("hunterchars", "rougeanim", "default");

		battleMenuOption = config->getBool("systemconfig", "battlemenu", true);

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
			ReplacePAK("SONICTEX", "SONICTEX_TRIAL");
			PrintDebug("Sonic textures replaced with red soled Trial shoes textures.");
			ReplaceMDL("SSONICMDL", "SSONICMDL_TR");
			PrintDebug("Super Sonic model replaced with enhanced Trial shoes model.");
			ReplacePAK("SSONICTEX", "SSONICTEX_TRIAL");
			PrintDebug("Super Sonic textures replaced with red soled Trial shoes textures.");
		}
		else if (sonicOption == "trialgray") {
			ReplaceMDL("SONICMDL", "SONICMDL_TR");
			PrintDebug("Sonic model replaced with enhanced Trial shoes model.");
			ReplacePAK("SONICTEX", "SONICTEX_TRIALGRAY");
			PrintDebug("Sonic textures replaced with gray soled Trial shoes textures.");
			ReplaceMDL("SSONICMDL", "SSONICMDL_TR");
			PrintDebug("Super Sonic model replaced with enhanced Trial shoes model.");
			ReplacePAK("SSONICTEX", "SSONICTEX_TRIALGRAY");
			PrintDebug("Super Sonic textures replaced with gray soled Trial shoes textures.");
		}
		else {
			PrintDebug("No replacements made.");
		}
		if (sonicOption != "off") {
			if (sonicaltOption == "gc") {
				ReplaceMDL("SONIC1MDL", "SONIC1MDL_EN");
				PrintDebug("Racesuit Sonic model replaced with enhanced model.");
			}
			if (sonicaltOption == "dc") {
				ReplaceMDL("SONIC1MDL", "SONIC1MDL_DC");
				PrintDebug("Racesuit Sonic model replaced with PSO model.");
				ReplacePAK("SONIC1TEX", "PSOSONICTEX");
				PrintDebug("Racesuit Sonic textures replaced with PSO textures.");
			}
		}

		PrintDebug("Begin Shadow initialization.");
		if (shadowOption == "default") {
			ReplaceMDL("TERIOSMDL", "TERIOSMDL_EN");
			PrintDebug("Shadow model replaced with enhanced model.");
			ReplaceMDL("SSHADOWMDL", "SSHADOWMDL_EN");
			PrintDebug("Super Shadow model replaced with enhanced model.");
			if (shadowaltOption == "gc") {
				ReplaceMDL("SHADOW1MDL", "SHADOW1MDL_EN");
				PrintDebug("Racesuit Shadow model replaced with enhanced model.");
			}
			if (shadowaltOption == "dc") {
				ReplaceMDL("SHADOW1MDL", "SHADOW1MDL_DC");
				PrintDebug("Racesuit Shadow model replaced with PSO model.");
				ReplacePAK("SHADOW1TEX", "PSOSHADOWTEX");
				PrintDebug("Racesuit Shadow textures replaced with PSO textures.");
			}
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
			ReplacePAK("TWALK1TEX", "TWALK1TEX_EN");
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

			if (knuxaltOption == "dc") {
				ReplaceMDL("BKNUCKMDL", "BKNUCKMDL_DC");
				PrintDebug("Knuckles alt model replaced with DC style model.");
				ReplacePAK("BKNUCKTEX", "BKNUCKTEX_DC");
				PrintDebug("Knuckles alt textures replaced with DC style textures.");
			}
			if (knuxaltOption == "gc") {
				ReplaceMDL("BKNUCKMDL", "BKNUCKMDL_EN");
				PrintDebug("Knuckles alt model replaced with enhanced model.");
			}
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
				PrintDebug("Rouge alt model replaced with DC style model.");
				ReplacePAK("BROUGETEX", "BROUGETEX_DC");
				PrintDebug("Rouge alt textures replaced with DC style textures.");
			}
			if (rougealtOption == "gc") {
				ReplaceMDL("BROUGEMDL", "BROUGEMDL_EN");
				PrintDebug("Rouge alt model replaced with enhanced model.");
			}
		}
		else {
			PrintDebug("No replacements made.");
		}
		if (rougeanmOption == "default") {
			ReplaceMDL("ROUGEMTN", "ROUGEMTN_EN");
			PrintDebug("Rouge animations replaced with enhanced animations.");
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


		if (battleMenuOption) {
			PrintDebug("Initializing Battle screen.");

			CharaObjectData* cod = (CharaObjectData*)GetProcAddress(hmodule, "_charaObject");

			if (sonicOption != "off") {

				ModelInfo* so_btl_mdl;
				if (sonicOption == "default") {
					so_btl_mdl = FindModel("BattleMenu\\Sonic_SOAP.sa2mdl");
				}
				else {
					so_btl_mdl = FindModel("BattleMenu\\Sonic_TRIAL.sa2mdl");
					ReplaceSingleTex("batadvPlayerChara", "sonic_soapshoes", "Textures", "stx_s000", 1061994, 64, 64);
				}

				cod[0].MainModel = so_btl_mdl->getmodel();
			}

			if (shadowOption != "off") {
				ModelInfo* sh_btl_mdl = FindModel("BattleMenu\\Shadow.sa2mdl");

				cod[1].MainModel = sh_btl_mdl->getmodel();
			}

			if (amyOption != "off") {
				ModelInfo* am_btl_mdl;

				if (amyOption == "default") {
					am_btl_mdl = FindModel("BattleMenu\\Amy_Default.sa2mdl");
				}
				else {
					am_btl_mdl = FindModel("BattleMenu\\Amy_Eyeliner.sa2mdl");
				}

				cod[6].MainModel = am_btl_mdl->getmodel();
			}

			if (metalOption != "off") {
				ModelInfo* sh_btl_mdl = FindModel("BattleMenu\\MetalSonic.sa2mdl");

				cod[7].MainModel = sh_btl_mdl->getmodel();
			}

			if (tailsOption != "off") {
				ModelInfo* tl_btl_mdl = FindModel("BattleMenu\\Tails.sa2mdl");

				cod[2].MainModel = tl_btl_mdl->getmodel();
			}

			if (eggmechOption != "off") {
				ModelInfo* eg_btl_mdl = FindModel("BattleMenu\\Eggman.sa2mdl");

				cod[3].MainModel = eg_btl_mdl->getmodel();
			}

			if (knuxOption != "off") {
				ModelInfo* kn_btl_mdl = FindModel("BattleMenu\\Knuckles.sa2mdl");

				cod[4].MainModel = kn_btl_mdl->getmodel();
			}

			if (rougeOption != "off") {
				ModelInfo* rg_btl_mdl = FindModel("BattleMenu\\Rouge.sa2mdl");

				cod[5].MainModel = rg_btl_mdl->getmodel();
			}

			if (tikalOption != "off") {
				ModelInfo* tk_btl_mdl = FindModel("BattleMenu\\Tikal.sa2mdl");

				cod[8].MainModel = tk_btl_mdl->getmodel();
			}

			if (chaosOption != "off") {
				ModelInfo* cz_btl_mdl = FindModel("BattleMenu\\Chaos.sa2mdl");

				cod[9].MainModel = cz_btl_mdl->getmodel();
			}
		}
		else {
			PrintDebug("Battle Screen unchanged.");
		}


		PrintDebug("Initialization done.");
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}
