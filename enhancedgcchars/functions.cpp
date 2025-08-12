#include "pch.h"

extern EGC_CONFIG mod_config;

// Config checking function

bool isActive(std::string input)
{
	if (input != "off")
	{
		return true;
	}
	return false;
}

void InitSonic()
{
	std::string value = mod_config.sonic;
	std::string altvalue = mod_config.sonicalt;

	PrintDebug("Begin Sonic initialization.");
	if (value == "default") {

		ReplaceMDL("SONICMDL", "SONICMDL_EN");
		PrintDebug("Sonic model replaced with enhanced model.");

		ReplaceMDL("SSONICMDL", "SSONICMDL_EN");
		PrintDebug("Super Sonic model replaced with enhanced model.");

	}
	else if (value == "trialred") {

		ReplaceMDL("SONICMDL", "SONICMDL_TR");
		PrintDebug("Sonic model replaced with enhanced Trial shoes model.");

		ReplacePAK("SONICTEX", "SONICTEX_TRIAL");
		PrintDebug("Sonic textures replaced with red soled Trial shoes textures.");

		ReplaceMDL("SSONICMDL", "SSONICMDL_TR");
		PrintDebug("Super Sonic model replaced with enhanced Trial shoes model.");

		ReplacePAK("SSONICTEX", "SSONICTEX_TRIAL");
		PrintDebug("Super Sonic textures replaced with red soled Trial shoes textures.");

	}
	else if (value == "trialgray") {

		ReplaceMDL("SONICMDL", "SONICMDL_TR");
		PrintDebug("Sonic model replaced with enhanced Trial shoes model.");

		ReplacePAK("SONICTEX", "SONICTEX_TRIALGRAY");
		PrintDebug("Sonic textures replaced with gray soled Trial shoes textures.");

		ReplaceMDL("SSONICMDL", "SSONICMDL_TR");
		PrintDebug("Super Sonic model replaced with enhanced Trial shoes model.");

		ReplacePAK("SSONICTEX", "SSONICTEX_TRIALGRAY");
		PrintDebug("Super Sonic textures replaced with gray soled Trial shoes textures.");

	}
	else if (value == "alt")
	{
		if (altvalue == "gc")
		{

			ReplaceMDL("SONICMDL", "SONIC1MDL_SP");
			ReplacePAK("SONICTEX", "SONIC1TEX");
			PrintDebug("Sonic model replaced with enhanced racesuit model.");

			ReplaceMDL("SSONICMDL", "SSONIC1MDL");
			ReplaceMDL("SSONICTEX", "SSONIC1TEX");
			PrintDebug("Super Sonic model replaced with enhanced racesuit model.");

		}
		if (altvalue == "dc")
		{

			ReplaceMDL("SONICMDL", "PSOSONICMDL_SP");
			ReplacePAK("SONICTEX", "PSOSONICTEX");
			PrintDebug("Sonic model replaced with PSO model.");

			ReplaceMDL("SSONICMDL", "PSOSSONICMDL");
			ReplaceMDL("SSONICTEX", "PSOSSONICTEX");
			PrintDebug("Super Sonic model replaced with PSO model.");

		}
	}
	else if (value == "hallow")
	{

		ReplaceMDL("SONICMDL", "HSONICMDL");
		ReplacePAK("SONICTEX", "HSONICTEX");

		ReplaceMDL("SSONICMDL", "HSSONICMDL");
		ReplacePAK("SSONICTEX", "HSSONICTEX");

	}
	else if (value == "xmas")
	{

		ReplaceMDL("SONICMDL", "XSONICMDL");
		ReplacePAK("SONICTEX", "XSONICTEX");

		ReplaceMDL("SSONICMDL", "XSSONICMDL");
		ReplacePAK("SSONICTEX", "XSSONICTEX");

	}
	else {
		PrintDebug("No replacements made.");
	}
	if (value != "off") {
		if (altvalue == "gc") {

			ReplaceMDL("SONIC1MDL", "SONIC1MDL_EN");
			PrintDebug("Racesuit Sonic model replaced with enhanced model.");

		}
		if (altvalue == "dc") {

			ReplaceMDL("SONIC1MDL", "PSOSONICMDL");
			PrintDebug("Racesuit Sonic model replaced with PSO model.");

			ReplacePAK("SONIC1TEX", "PSOSONICTEX");
			PrintDebug("Racesuit Sonic textures replaced with PSO textures.");

		}
	}
}

void InitShadow()
{
	std::string value = mod_config.shadow;
	std::string altvalue = mod_config.shadow;

	PrintDebug("Begin Shadow initialization.");
	if (value == "default") {

		ReplaceMDL("TERIOSMDL", "TERIOSMDL_EN");
		PrintDebug("Shadow model replaced with enhanced model.");

		ReplaceMDL("SSHADOWMDL", "SSHADOWMDL_EN");
		PrintDebug("Super Shadow model replaced with enhanced model.");

	}
	else if (value == "alt")
	{
		if (altvalue == "gc") {

			ReplaceMDL("TERIOSMDL", "SHADOW1MDL_SP");
			ReplacePAK("TERIOSTEX", "SHADOW1TEX");
			PrintDebug("Shadow model replaced with enhanced racesuit model.");

			ReplaceMDL("SSHADOWMDL", "SSHADOW1MDL");
			ReplacePAK("SSHADOWTEX", "SSHADOW1TEX");
			PrintDebug("Super Shadow model replaced with enhanced racesuit model.");

		}
		if (altvalue == "dc") {

			ReplaceMDL("TERIOSMDL", "PSOSHADOWMDL_SP");
			ReplacePAK("TERIOSTEX", "PSOSHADOWTEX");
			PrintDebug("Shadow model replaced with PSO model.");

			ReplaceMDL("SSHADOWMDL", "PSOSSHADOWMDL");
			ReplacePAK("SSHADOWTEX", "PSOSSHADOWTEX");
			PrintDebug("Super Shadow model replaced with PSO model.");

		}
	}
	else if (value == "xmas")
	{
		ReplaceMDL("TERIOSMDL", "XSHADOWMDL");
		ReplacePAK("TERIOSTEX", "XSHADOWTEX");

		ReplaceMDL("SSHADOWMDL", "XSSHADOWMDL");
		ReplacePAK("SSHADOWTEX", "XSSHADOWTEX");
	}
	else if (value == "hallow")
	{
		ReplaceMDL("TERIOSMDL", "HSHADOWMDL");
		ReplacePAK("TERIOSTEX", "HSHADOWTEX");

		ReplaceMDL("SSHADOWMDL", "HSSHADOWMDL");
		ReplacePAK("SSHADOWTEX", "HSSHADOWTEX");
	}
	else {
		PrintDebug("No replacements made.");
	}
	if (value != "off") {
		if (altvalue == "gc") {

			ReplaceMDL("SHADOW1MDL", "SHADOW1MDL_EN");
			PrintDebug("Racesuit Shadow model replaced with enhanced model.");

		}
		if (altvalue == "dc") {

			ReplaceMDL("SHADOW1MDL", "PSOSHADOWMDL");
			PrintDebug("Racesuit Shadow model replaced with PSO model.");

			ReplacePAK("SHADOW1TEX", "PSOSHADOWTEX");
			PrintDebug("Racesuit Shadow textures replaced with PSO textures.");
		}
	}
}

void InitAmy()
{
	std::string value = mod_config.amy;

	PrintDebug("Begin Amy initialization.");
	if (value == "default") {

		ReplaceMDL("AMYMDL", "AMYMDL_EN");
		PrintDebug("Amy model replaced with enhanced model.");

	}
	else if (value == "eyeliner") {

		ReplaceMDL("AMYMDL", "AMYMDL_EL");
		PrintDebug("Amy model replaced with eyeliner model.");

	}
	else {
		PrintDebug("No replacements made.");
	}
	/*
	if (amyHammer)
	{
		PrintDebug("Replacing Amy's hammer");
		init_amy();
	}
	*/
}

void InitMetal()
{
	std::string value = mod_config.metal;

	PrintDebug("Begin Metal Sonic initialization.");
	if (value == "default") {

		ReplaceMDL("METALSONICMDL", "METALSONICMDL_EN");
		PrintDebug("Metal Sonic model replaced with enhanced model.");

	}
	else {
		PrintDebug("No replacements made.");
	}
}

void InitTails()
{

	std::string value = mod_config.mech_tails;
	std::string value2 = mod_config.miles;

	PrintDebug("Begin Cyclone initialization.");
	if (value == "default") {

		ReplaceMDL("TWALKMDL", "TWALKMDL_EN");
		PrintDebug("Cyclone model replaced with enhanced model.");
		ReplaceMDL("TWALK1MDL", "TWALK1MDL_EN");
		PrintDebug("Typhoon model replaced with enhanced model.");

	}
	else if (value == "alt") {

		ReplaceMDL("TWALKMDL", "TWALK1MDL_SP");
		ReplacePAK("TWALKTEX", "TWALK1TEX");

	}
	else if (value == "hallow") {

		ReplaceMDL("TWALKMDL", "HTWALKMDL");
		ReplacePAK("TWALKTEX", "HTWALKTEX");

	}
	else if (value == "xmas") {

		ReplaceMDL("TWALKMDL", "XTWALKMDL");
		ReplacePAK("TWALKTEX", "XTWALKTEX");

	}
	else {
		PrintDebug("No replacements made.");
	}

	PrintDebug("Begin Mechless Tails initialization.");
	if (value2 == "default") {

		ReplaceMDL("MILESMDL", "MILESMDL_EN");
		PrintDebug("Tails model replaced with enhanced model.");

	}
	else {
		PrintDebug("No replacements made.");
	}
}

void InitEggman()
{
	std::string value = mod_config.mech_eggman;
	std::string valuealt = mod_config.eggman_alt;
	std::string value2 = mod_config.eggman;
	
	PrintDebug("Begin Egg Walker initialization.");
	if (value == "default") {

		ReplaceMDL("EWALKMDL", "EWALKMDL_EN");
		PrintDebug("Egg Walker model replaced with enhanced model.");

	}
	else if (value == "alt")
	{
		if (valuealt == "gc") {

			ReplaceMDL("EWALKMDL", "EWALK2MDL_SP");
			ReplacePAK("EWALKTEX", "EWALK2TEX");
			PrintDebug("Egg Walker model replaced with enhanced alt model.");

		}
		if (valuealt == "dc") {

			ReplaceMDL("EWALKMDL", "EWALK1MDL_SP");
			ReplacePAK("EWALKTEX", "EWALK1TEX");
			PrintDebug("Egg Walker model replaced with Egg Camo model.");

		}
	}
	else if (value == "hallow")
	{

		ReplaceMDL("EWALKMDL", "HEWALKMDL");
		ReplacePAK("EWALKTEX", "HEWALKTEX");

	}
	else if (value == "xmas")
	{

		ReplaceMDL("EWALKMDL", "XEWALKMDL");
		ReplacePAK("EWALKTEX", "XEWALKTEX");

	}
	else {
		PrintDebug("No replacements made.");
	}
	if (value != "off") {
		if (valuealt == "gc") {

			ReplaceMDL("EWALK2MDL", "EWALK2MDL_EN");
			PrintDebug("Egg Tank model replaced with enhanced model.");

		}
		if (valuealt == "dc") {

			ReplaceMDL("EWALK2MDL", "EWALK1MDL_EN");
			PrintDebug("Egg Tank model replaced with Egg Camo model.");
			ReplacePAK("EWALK2TEX", "EWALK1TEX");
			PrintDebug("Egg Tank textures replaces with Egg Camo textures.");

		}
	}

	PrintDebug("Begin Mechless Eggman initialization.");
	if (value2 == "default") {

		ReplaceMDL("EGGMDL", "EGGMDL_EN");
		PrintDebug("Eggman model replaced with enhanced model.");

	}
	else {
		PrintDebug("No replacements made.");
	}
}

void InitKnuckles()
{
	std::string value = mod_config.knuckles;
	std::string valuealt = mod_config.knucklesalt;
	PrintDebug("Begin Knuckles initialization.");
	if (value == "default") {
		ReplaceMDL("KNUCKMDL", "KNUCKMDL_EN");
		PrintDebug("Knuckles model replaced with enhanced model.");

	}
	else if (value == "alt") {
		if (valuealt == "dc") {
			ReplaceMDL("KNUCKMDL", "BKNUCKMDL_DCSP");
			PrintDebug("Knuckles alt model replaced with DC style model.");
			ReplacePAK("KNUCKTEX", "BKNUCKTEX_DC");
			PrintDebug("Knuckles alt textures replaced with DC style textures.");
		}
		if (valuealt == "gc") {
			ReplaceMDL("KNUCKMDL", "BKNUCKMDL_SP");
			ReplacePAK("KNUCKTEX", "BKNUCKTEX");
			PrintDebug("Knuckles alt model replaced with enhanced model.");
		}
	}
	else if (value == "hallow") {

		ReplaceMDL("KNUCKMDL", "HKNUCKMDL");
		ReplacePAK("KNUCKTEX", "HKNUCKTEX");

	}
	else if (value == "xmas") {

		ReplaceMDL("KNUCKMDL", "XKNUCKMDL");
		ReplacePAK("KNUCKTEX", "XKNUCKTEX");

	}
	else {
		PrintDebug("No replacements made.");
	}
	if (value != "off") {

		if (valuealt == "dc") {
			ReplaceMDL("BKNUCKMDL", "BKNUCKMDL_DC");
			PrintDebug("Knuckles alt model replaced with DC style model.");
			ReplacePAK("BKNUCKTEX", "BKNUCKTEX_DC");
			PrintDebug("Knuckles alt textures replaced with DC style textures.");
		}
		if (valuealt == "gc") {
			ReplaceMDL("BKNUCKMDL", "BKNUCKMDL_EN");
			PrintDebug("Knuckles alt model replaced with enhanced model.");
		}
	}
}

void InitRouge()
{
	std::string value = mod_config.rouge;
	std::string valuealt = mod_config.rougealt;
	std::string valueanm = mod_config.rougeanm;

	PrintDebug("Begin Rouge initialization.");
	if (value == "default") {
		ReplaceMDL("ROUGEMDL", "ROUGEMDL_EN");
		PrintDebug("Rouge model replaced with enhanced model.");

	}
	else if (value == "alt") {

		if (valuealt == "dc") {
			ReplaceMDL("ROUGEMDL", "BROUGEMDL_DCSP");
			ReplacePAK("ROUGETEX", "BROUGETEX_DC");
			PrintDebug("Rouge model replaced with DC style model.");
		}
		if (valuealt == "gc") {
			ReplaceMDL("ROUGEMDL", "BROUGEMDL_SP");
			ReplacePAK("ROUGETEX", "BROUGETEX");
			PrintDebug("Rouge model replaced with enhanced alt model.");
		}
	}
	else if (value == "hallow") {

		ReplaceMDL("ROUGEMDL", "HROUGEMDL");
		ReplacePAK("ROUGETEX", "HROUGETEX");

	}
	else if (value == "xmas") {

		ReplaceMDL("ROUGEMDL", "XROUGEMDL");
		ReplacePAK("ROUGETEX", "XROUGETEX");

	}
	else {
		PrintDebug("No replacements made.");
	}
	if (value != "off") {

		if (valuealt == "dc") {
			ReplaceMDL("BROUGEMDL", "BROUGEMDL_DC");
			PrintDebug("Rouge alt model replaced with DC style model.");
			ReplacePAK("BROUGETEX", "BROUGETEX_DC");
			PrintDebug("Rouge alt textures replaced with DC style textures.");
		}
		if (valuealt == "gc") {
			ReplaceMDL("BROUGEMDL", "BROUGEMDL_EN");
			PrintDebug("Rouge alt model replaced with enhanced model.");
		}
	}
	if (valueanm == "default") {
		ReplaceMDL("ROUGEMTN", "ROUGEMTN_EN");
		PrintDebug("Rouge animations replaced with enhanced animations.");
	}
}

void InitTikal()
{
	std::string value = mod_config.tikal;
	std::string valueanm = mod_config.tikalanm;

	PrintDebug("Begin Tikal initialization.");
	if (value == "default") {
		ReplaceMDL("TICALMDL", "TICALMDL_EN");
		PrintDebug("Tikal model replaced with enhanced model.");
	}
	else {
		PrintDebug("No replacements made.");
	}
	if (valueanm == "default") {
		ReplaceMDL("TICALMTN", "TICALMTN_EN");
		PrintDebug("Tikal animations replaced with enhanced animations.");
	}
}

void InitChaos0()
{
	std::string value = mod_config.chaos;

	PrintDebug("Begin Chaos Zero initialization.");
	if (value == "default") {
		ReplaceMDL("CHAOS0MDL", "CHAOS0MDL_EN");
		PrintDebug("Chaos Zero model replaced with enhanced model.");
	}
	else {
		PrintDebug("No replacements made.");
	}
}

void InitBattleMenu()
{
	if (mod_config.menu) {
		PrintDebug("Initializing Battle screen.");

		ReplacePAK("batadvPlayerChara", "batadvPlayerChara_EGC");
		CharaObjectData* cod = (CharaObjectData*)GetProcAddress(globaldll, "_charaObject");

		static NJS_TEXNAME batadvtexnames_egc[153]{};
		NJS_TEXLIST* battex = (NJS_TEXLIST*)GetProcAddress(globaldll, "texlist_batadvPlayerChara");
		NJS_TEXLIST batadvextex = { arrayptrandlength(batadvtexnames_egc) };
		battex[0] = batadvextex;

		if (isActive(mod_config.sonic)) {

			ModelInfo* so_btl_mdl = FindModel("BattleMenu\\Base\\Sonic_SOAP.sa2mdl");;
			ModelInfo* sso_btl_mdl = FindModel("BattleMenu\\Base\\SuperSonic_SOAP.sa2mdl");;

			if (mod_config.sonic == "trial") {
				so_btl_mdl = FindModel("BattleMenu\\Base\\Sonic_TRIAL.sa2mdl");
				sso_btl_mdl = FindModel("BattleMenu\\Base\\SuperSonic_TRIAL.sa2mdl");
			}
			else if (mod_config.sonic == "alt") {
				if (mod_config.sonicalt == "gc") {
					so_btl_mdl = FindModel("BattleMenu\\Alt_GC\\Sonic_RACESUIT.sa2mdl");
					sso_btl_mdl = FindModel("BattleMenu\\Alt_GC\\SuperSonic_RACESUIT.sa2mdl");
				}
				if (mod_config.sonicalt == "dc") {
					so_btl_mdl = FindModel("BattleMenu\\Alt_DC\\Sonic_PSO.sa2mdl");
					sso_btl_mdl = FindModel("BattleMenu\\Alt_DC\\SuperSonic_PSO.sa2mdl");
				}
			}
			else if (mod_config.sonic == "xmas") {
				so_btl_mdl = FindModel("BattleMenu\\Christmas\\Sonic_XMAS.sa2mdl");
				sso_btl_mdl = FindModel("BattleMenu\\Christmas\\SuperSonic_XMAS.sa2mdl");
			}
			else if (mod_config.sonic == "hallow") {
				so_btl_mdl = FindModel("BattleMenu\\Halloween\\Sonic_HW.sa2mdl");
				sso_btl_mdl = FindModel("BattleMenu\\Halloween\\SuperSonic_HW.sa2mdl");
			}

			cod[0].MainModel = so_btl_mdl->getmodel();
			cod[0].SuperModel = sso_btl_mdl->getmodel();
		}

		if (isActive(mod_config.shadow)) {
			ModelInfo* sh_btl_mdl = FindModel("BattleMenu\\Base\\Shadow.sa2mdl");
			ModelInfo* ssh_btl_mdl = FindModel("BattleMenu\\Base\\SuperShadow.sa2mdl");

			if (mod_config.shadow == "alt")
			{
				if (mod_config.shadowalt == "gc") {
					sh_btl_mdl = FindModel("BattleMenu\\Alt_GC\\Shadow_RACESUIT.sa2mdl");
					ssh_btl_mdl = FindModel("BattleMenu\\Alt_GC\\SuperShadow_RACESUIT.sa2mdl");
				}
				if (mod_config.shadowalt == "dc") {
					sh_btl_mdl = FindModel("BattleMenu\\Alt_DC\\Shadow_PSO.sa2mdl");
					ssh_btl_mdl = FindModel("BattleMenu\\Alt_DC\\SuperShadow_PSO.sa2mdl");
				}
			}
			else if (mod_config.shadow == "xmas") {
				sh_btl_mdl = FindModel("BattleMenu\\Christmas\\Shadow_XMAS.sa2mdl");
				ssh_btl_mdl = FindModel("BattleMenu\\Christmas\\SuperShadow_XMAS.sa2mdl");
			}
			else if (mod_config.shadow == "hallow") {
				sh_btl_mdl = FindModel("BattleMenu\\Christmas\\Shadow_HW.sa2mdl");
				ssh_btl_mdl = FindModel("BattleMenu\\Christmas\\SuperShadow_HW.sa2mdl");
			}

			cod[1].MainModel = sh_btl_mdl->getmodel();
			cod[1].SuperModel = ssh_btl_mdl->getmodel();
		}

		if (isActive(mod_config.amy)) {
			ModelInfo* am_btl_mdl = FindModel("BattleMenu\\Base\\Amy_Default.sa2mdl");;

			if (mod_config.amy == "eyeliner") {
				am_btl_mdl = FindModel("BattleMenu\\Base\\Amy_Eyeliner.sa2mdl");
			}

			cod[6].MainModel = am_btl_mdl->getmodel();
		}

		if (isActive(mod_config.metal)) {
			ModelInfo* sh_btl_mdl = FindModel("BattleMenu\\Base\\MetalSonic.sa2mdl");

			cod[7].MainModel = sh_btl_mdl->getmodel();
		}

		if (isActive(mod_config.mech_tails)) {
			ModelInfo* tl_btl_mdl = FindModel("BattleMenu\\Base\\Tails.sa2mdl");

			if (mod_config.mech_tails == "alt") {
				tl_btl_mdl = FindModel("BattleMenu\\Alt_DC\\Tails_Typhoon.sa2mdl");
			}

			cod[2].MainModel = tl_btl_mdl->getmodel();
		}

		if (mod_config.mech_eggman == "default") {
			ModelInfo* eg_btl_mdl = FindModel("BattleMenu\\Base\\Eggman.sa2mdl");
			ModelInfo* eg_acc = FindModel("BattleMenu\\Base\\Eggman_Windshield.sa2mdl");

			cod[3].MainModel = eg_btl_mdl->getmodel();

			cod[3].AccessoryAttachNode = (NJS_OBJECT*)eg_btl_mdl->getdata("object_0033E884");
			cod[3].AccessoryModel = eg_acc->getmodel();
		}
		if (mod_config.mech_eggman == "alt" && mod_config.eggman_alt == "gc") {
			ModelInfo* eg_btl_mdl = FindModel("BattleMenu\\Alt_GC\\Eggman_Tank.sa2mdl");
			ModelInfo* eg_acc = FindModel("BattleMenu\\Alt_GC\\Eggman_Windshield.sa2mdl");

			cod[3].MainModel = eg_btl_mdl->getmodel();

			cod[3].AccessoryAttachNode = (NJS_OBJECT*)eg_btl_mdl->getdata("object_0033E884");
			cod[3].AccessoryModel = eg_acc->getmodel();
		}

		if (isActive(mod_config.knuckles)) {
			ModelInfo* kn_btl_mdl = FindModel("BattleMenu\\Base\\Knuckles.sa2mdl");

			cod[4].MainModel = kn_btl_mdl->getmodel();
		}

		if (isActive(mod_config.rouge)) {
			ModelInfo* rg_btl_mdl = FindModel("BattleMenu\\Base\\Rouge.sa2mdl");

			cod[5].MainModel = rg_btl_mdl->getmodel();
		}

		if (isActive(mod_config.tikal)) {
			ModelInfo* tk_btl_mdl = FindModel("BattleMenu\\Base\\Tikal.sa2mdl");

			cod[8].MainModel = tk_btl_mdl->getmodel();
		}

		if (isActive(mod_config.chaos)) {
			ModelInfo* cz_btl_mdl = FindModel("BattleMenu\\Base\\Chaos.sa2mdl");

			cod[9].MainModel = cz_btl_mdl->getmodel();
		}
	}
	else {
		PrintDebug("Battle Screen unchanged.");
	}
}

void InitKarts()
{
	if (mod_config.karts)
	{
		PrintDebug("Initializing Kart models.");

		NJS_TEXNAME texname_cartdata[103]{};
		NJS_TEXLIST texlist_cartdata[1] = { arrayptrandlength(texname_cartdata) };

		NJS_TEXNAME texname_kartexmodel[69]{};
		NJS_TEXLIST texlist_kartexmodel[1] = { arrayptrandlength(texname_kartexmodel) };

		NJS_TEXLIST* karttex = (NJS_TEXLIST*)GetProcAddress(globaldll, "texlist_cartData_cartSpecial");
		NJS_TEXLIST* exkarttex = (NJS_TEXLIST*)GetProcAddress(globaldll, "texlist_kartExModel_cartSpecial");

		karttex = texlist_cartdata;
		exkarttex = texlist_kartexmodel;

		ReplacePAK("cartData", "cartData_EN");
		ReplacePAK("kartExModel", "kartExModel_EN");


		NJS_OBJECT** exKart_mdls = (NJS_OBJECT**)GetProcAddress(globaldll, "exModels");

		KartSpecialInfo* specialInfo = (KartSpecialInfo*)GetProcAddress(globaldll, "specialInfo");
		KartMenu* player00 = (KartMenu*)GetProcAddress(globaldll, "player00");

		if (isActive(mod_config.sonic))
		{
			PrintDebug("Replacing Sonic's models...");
			ModelInfo* so_kart_mdl = FindModel("KartRacing\\default_kart_sonic.sa2mdl");
			ModelInfo* so_exkart_mdl = FindModel("KartRacing\\extra_kart_sonic.sa2mdl");

			player00[p0_SONIC].KartModel = so_kart_mdl->getmodel();
			player00[p0_SONIC_EX].KartModel = so_exkart_mdl->getmodel();
			specialInfo[sp_SONIC].Model = so_kart_mdl->getmodel();
			exKart_mdls[SONIC] = so_exkart_mdl->getmodel();
		}

		if (isActive(mod_config.shadow))
		{
			PrintDebug("Replacing Shadow's models...");
			ModelInfo* sh_kart_mdl = FindModel("KartRacing\\default_kart_shadow.sa2mdl");
			ModelInfo* sh_exkart_mdl = FindModel("KartRacing\\extra_kart_shadow.sa2mdl");

			player00[p0_SHADOW].KartModel = sh_kart_mdl->getmodel();
			player00[p0_SHADOW_EX].KartModel = sh_exkart_mdl->getmodel();
			specialInfo[sp_SHADOW].Model = sh_kart_mdl->getmodel();
			exKart_mdls[SHADOW] = sh_exkart_mdl->getmodel();
		}

		if (isActive(mod_config.mech_tails))
		{
			PrintDebug("Replacing Tails's models...");
			ModelInfo* tl_kart_mdl = FindModel("KartRacing\\default_kart_tails.sa2mdl");
			ModelInfo* tl_storykart_mdl = FindModel("KartRacing\\storymode_kart_tails.sa2mdl");

			player00[p0_TAILS].KartModel = tl_kart_mdl->getmodel();
			specialInfo[sp_TAILS].Model = tl_kart_mdl->getmodel();
			specialInfo[sp_STORYMODE_TAILS].Model = tl_storykart_mdl->getmodel();
		}

		if (isActive(mod_config.mech_eggman))
		{
			PrintDebug("Replacing Eggman's models...");
			ModelInfo* eg_kart_mdl = FindModel("KartRacing\\default_kart_eggman.sa2mdl");
			ModelInfo* eg_exkart_mdl = FindModel("KartRacing\\extra_kart_eggman.sa2mdl");

			player00[p0_EGGMAN].KartModel = eg_kart_mdl->getmodel();
			player00[p0_EGGMAN_EX].KartModel = eg_exkart_mdl->getmodel();
			specialInfo[sp_EGGMAN].Model = eg_kart_mdl->getmodel();
			exKart_mdls[EGGMAN] = eg_exkart_mdl->getmodel();
		}

		if (isActive(mod_config.knuckles))
		{
			PrintDebug("Replacing Knuckles's models...");
			ModelInfo* kn_kart_mdl = FindModel("KartRacing\\default_kart_knuckles.sa2mdl");
			ModelInfo* kn_exkart_mdl = FindModel("KartRacing\\extra_kart_knuckles.sa2mdl");

			player00[p0_KNUCKLES].KartModel = kn_kart_mdl->getmodel();
			player00[p0_KNUCKLES_EX].KartModel = kn_exkart_mdl->getmodel();
			specialInfo[sp_KNUCKLES].Model = kn_kart_mdl->getmodel();
			exKart_mdls[KNUCKLES] = kn_exkart_mdl->getmodel();
		}

		if (isActive(mod_config.rouge))
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
}

void InitChaoWalker()
{
	std::string value = mod_config.chaowalker;

	PrintDebug("Begin Chao Walker initialization.");
	if (value == "default") {
		ReplaceMDL("CWALKMDL", "CWALKMDL_EN");
		PrintDebug("Chao Walker model replaced with enhanced model.");
	}
	else {
		PrintDebug("No replacements made.");
	}
}
void InitDarkChaoWalker()
{
	std::string value = mod_config.darkwalker;

	PrintDebug("Begin Dark Chao Walker initialization.");
	if (value == "default") {
		ReplaceMDL("DWALKMDL", "DWALKMDL_EN");
		PrintDebug("Dark Chao Walker model replaced with enhanced model.");
	}
	else {
		PrintDebug("No replacements made.");
	}
}

/*

FunctionHook<void, int> amy_loadptr(LoadAmy);

# Scrapped option for Amy's hammer

void
amy_hammer_hook(int pno)
{
	amy_loadptr.Original(pno);
}

void init_amy()
{
	amy_loadptr.Hook(amy_hammer_hook);
}
*/