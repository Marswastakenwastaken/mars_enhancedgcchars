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
std::string
tikalanmOption = "default";

bool
battleMenuOption = true;
bool
kartRaceOption = true;

enum player00_chars {
	p0_SONIC = 0,
	p0_TAILS = 1,
	p0_KNUCKLES = 2,
	p0_SHADOW = 3,
	p0_EGGMAN = 4,
	p0_ROUGE = 5,
	p0_SONIC_EX = 6,
	p0_CHAO = 7,
	p0_KNUCKLES_EX = 8,
	p0_SHADOW_EX = 9,
	p0_EGGMAN_EX = 10,
	p0_EGGROBO = 11
};

enum specialinfo_chars {
	sp_STORYMODE_TAILS = 0,
	sp_STORYMODE_ROUGE = 1,
	sp_SONIC = 2,
	sp_KNUCKLES = 3,
	sp_TAILS = 4,
	sp_EGGMAN = 5,
	sp_SHADOW = 6,
	sp_ROUGE = 7
};

enum exmodels_chars {
	SONIC = 0,
	CHAO = 1,
	KNUCKLES = 2,
	SHADOW = 3,
	EGGMAN = 4,
	EGGROBO = 5
};

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

		milesOption = config->getString("mechlesschars", "miles", "default");
		eggOption = config->getString("mechlesschars", "egg", "default");

		// Alt Configs

		sonicaltOption = config->getString("speedchars", "sonicalt", "gc");
		shadowaltOption = config->getString("speedchars", "shadowalt", "gc");
		knuxaltOption = config->getString("hunterchars", "knuckalt", "gc");
		rougealtOption = config->getString("hunterchars", "rougealt", "gc");
		eggaltOption = config->getString("mechchars", "eggalt", "gc");

		rougeanmOption = config->getString("hunterchars", "rougeanim", "default");
		tikalanmOption = config->getString("hunterchars", "tikalanim", "default");

		battleMenuOption = config->getBool("systemconfig", "battlemenu", true);
		kartRaceOption = config->getBool("systemconfig", "karts", true);

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
		if (tikalanmOption == "default") {
			ReplaceMDL("TICALMTN", "TICALMTN_EN");
			PrintDebug("Tikal animations replaced with enhanced animations.");
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

			if (isActive(sonicOption)) {

				ModelInfo* so_btl_mdl;
				ModelInfo* sso_btl_mdl;
				if (sonicOption == "default") {
					so_btl_mdl = FindModel("BattleMenu\\Sonic_SOAP.sa2mdl");
					sso_btl_mdl = FindModel("BattleMenu\\SuperSonic_SOAP.sa2mdl");
				}
				else {
					so_btl_mdl = FindModel("BattleMenu\\Sonic_TRIAL.sa2mdl");
					sso_btl_mdl = FindModel("BattleMenu\\SuperSonic_TRIAL.sa2mdl");
					ReplaceSingleTex("batadvPlayerChara", "sonic_soapshoes", "Textures", "stx_s000", 1061994, 64, 64);
				}

				cod[0].MainModel = so_btl_mdl->getmodel();
				cod[0].SuperModel = sso_btl_mdl->getmodel();
			}

			if (isActive(shadowOption)) {
				ModelInfo* sh_btl_mdl = FindModel("BattleMenu\\Shadow.sa2mdl");
				ModelInfo* ssh_btl_mdl = FindModel("BattleMenu\\SuperShadow.sa2mdl");

				cod[1].MainModel = sh_btl_mdl->getmodel();
				cod[1].SuperModel = ssh_btl_mdl->getmodel();
			}

			if (isActive(amyOption)) {
				ModelInfo* am_btl_mdl;

				if (amyOption == "default") {
					am_btl_mdl = FindModel("BattleMenu\\Amy_Default.sa2mdl");
				}
				else {
					am_btl_mdl = FindModel("BattleMenu\\Amy_Eyeliner.sa2mdl");
				}

				cod[6].MainModel = am_btl_mdl->getmodel();
			}

			if (isActive(metalOption)) {
				ModelInfo* sh_btl_mdl = FindModel("BattleMenu\\MetalSonic.sa2mdl");

				cod[7].MainModel = sh_btl_mdl->getmodel();
			}

			if (isActive(tailsOption)) {
				ModelInfo* tl_btl_mdl = FindModel("BattleMenu\\Tails.sa2mdl");

				cod[2].MainModel = tl_btl_mdl->getmodel();
			}

			if (isActive(eggmechOption)) {
				ModelInfo* eg_btl_mdl = FindModel("BattleMenu\\Eggman.sa2mdl");
				ModelInfo* eg_acc = FindModel("BattleMenu\\Eggman_Windshield.sa2mdl");

				cod[3].MainModel = eg_btl_mdl->getmodel();

				cod[3].AccessoryAttachNode = (NJS_OBJECT*)eg_btl_mdl->getdata("object_0033E884");
				cod[3].AccessoryModel = eg_acc->getmodel();
			}

			if (isActive(knuxOption)) {
				ModelInfo* kn_btl_mdl = FindModel("BattleMenu\\Knuckles.sa2mdl");

				cod[4].MainModel = kn_btl_mdl->getmodel();
			}

			if (isActive(rougeOption)) {
				ModelInfo* rg_btl_mdl = FindModel("BattleMenu\\Rouge.sa2mdl");

				cod[5].MainModel = rg_btl_mdl->getmodel();
			}

			if (isActive(tikalOption)) {
				ModelInfo* tk_btl_mdl = FindModel("BattleMenu\\Tikal.sa2mdl");

				cod[8].MainModel = tk_btl_mdl->getmodel();
			}

			if (isActive(chaosOption)) {
				ModelInfo* cz_btl_mdl = FindModel("BattleMenu\\Chaos.sa2mdl");

				cod[9].MainModel = cz_btl_mdl->getmodel();
			}
		}
		else {
			PrintDebug("Battle Screen unchanged.");
		}

		if (kartRaceOption)
		{
			PrintDebug("Initializing Kart models.");

			NJS_TEXNAME texname_cartdata[103]{};
			NJS_TEXLIST texlist_cartdata[1] = { arrayptrandlength(texname_cartdata) };

			NJS_TEXNAME texname_kartexmodel[69]{};
			NJS_TEXLIST texlist_kartexmodel[1] = { arrayptrandlength(texname_kartexmodel) };

			NJS_TEXLIST* karttex = (NJS_TEXLIST*)GetProcAddress(hmodule, "texlist_cartData_cartSpecial");
			NJS_TEXLIST* exkarttex = (NJS_TEXLIST*)GetProcAddress(hmodule, "texlist_kartExModel_cartSpecial");

			karttex = texlist_cartdata;
			exkarttex = texlist_kartexmodel;

			ReplacePAK("cartData", "cartData_EN");
			ReplacePAK("kartExModel", "kartExModel_EN");


			NJS_OBJECT** exKart_mdls = (NJS_OBJECT**)GetProcAddress(hmodule, "exModels");

			KartSpecialInfo* specialInfo = (KartSpecialInfo*)GetProcAddress(hmodule, "specialInfo");
			KartMenu* player00 = (KartMenu*)GetProcAddress(hmodule, "player00");

			if (isActive(sonicOption))
			{
				PrintDebug("Replacing Sonic's models...");
				ModelInfo* so_kart_mdl = FindModel("KartRacing\\default_kart_sonic.sa2mdl");
				ModelInfo* so_exkart_mdl = FindModel("KartRacing\\extra_kart_sonic.sa2mdl");

				player00[p0_SONIC].KartModel = so_kart_mdl->getmodel();
				player00[p0_SONIC_EX].KartModel = so_exkart_mdl->getmodel();
				specialInfo[sp_SONIC].Model = so_kart_mdl->getmodel();
				exKart_mdls[SONIC] = so_exkart_mdl->getmodel();
			}

			if (isActive(shadowOption))
			{
				PrintDebug("Replacing Shadow's models...");
				ModelInfo* sh_kart_mdl = FindModel("KartRacing\\default_kart_shadow.sa2mdl");
				ModelInfo* sh_exkart_mdl = FindModel("KartRacing\\extra_kart_shadow.sa2mdl");

				player00[p0_SHADOW].KartModel = sh_kart_mdl->getmodel();
				player00[p0_SHADOW_EX].KartModel = sh_exkart_mdl->getmodel();
				specialInfo[sp_SHADOW].Model = sh_kart_mdl->getmodel();
				exKart_mdls[SHADOW] = sh_exkart_mdl->getmodel();
			}

			if (isActive(tailsOption))
			{
				PrintDebug("Replacing Tails's models...");
				ModelInfo* tl_kart_mdl = FindModel("KartRacing\\default_kart_tails.sa2mdl");
				ModelInfo* tl_storykart_mdl = FindModel("KartRacing\\storymode_kart_tails.sa2mdl");

				player00[p0_TAILS].KartModel = tl_kart_mdl->getmodel();
				specialInfo[sp_TAILS].Model = tl_kart_mdl->getmodel();
				specialInfo[sp_STORYMODE_TAILS].Model = tl_storykart_mdl->getmodel();
			}

			if (isActive(eggOption))
			{
				PrintDebug("Replacing Eggman's models...");
				ModelInfo* eg_kart_mdl = FindModel("KartRacing\\default_kart_eggman.sa2mdl");
				ModelInfo* eg_exkart_mdl = FindModel("KartRacing\\extra_kart_eggman.sa2mdl");

				player00[p0_EGGMAN].KartModel = eg_kart_mdl->getmodel();
				player00[p0_EGGMAN_EX].KartModel = eg_exkart_mdl->getmodel();
				specialInfo[sp_EGGMAN].Model = eg_kart_mdl->getmodel();
				exKart_mdls[EGGMAN] = eg_exkart_mdl->getmodel();
			}

			if (isActive(knuxOption))
			{
				PrintDebug("Replacing Knuckles's models...");
				ModelInfo* kn_kart_mdl = FindModel("KartRacing\\default_kart_knuckles.sa2mdl");
				ModelInfo* kn_exkart_mdl = FindModel("KartRacing\\extra_kart_knuckles.sa2mdl");

				player00[p0_KNUCKLES].KartModel = kn_kart_mdl->getmodel();
				player00[p0_KNUCKLES_EX].KartModel = kn_exkart_mdl->getmodel();
				specialInfo[sp_KNUCKLES].Model = kn_kart_mdl->getmodel();
				exKart_mdls[KNUCKLES] = kn_exkart_mdl->getmodel();
			}

			if (isActive(rougeOption))
			{
				PrintDebug("Replacing Rouge's models...");
				ModelInfo* rg_kart_mdl = FindModel("KartRacing\\default_kart_rouge.sa2mdl");
				ModelInfo* rg_storykart_mdl = FindModel("KartRacing\\storymode_kart_rouge.sa2mdl");

				player00[p0_ROUGE].KartModel = rg_kart_mdl->getmodel();
				specialInfo[sp_ROUGE].Model = rg_kart_mdl->getmodel();
				specialInfo[sp_STORYMODE_ROUGE].Model = rg_storykart_mdl->getmodel();
			}

		}
		else {
			PrintDebug("Kart models unchanged.");
		}

		PrintDebug("Initialization done.");
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}
