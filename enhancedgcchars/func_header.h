#pragma once

extern HelperFunctions GlobalHelperFunctions;

#define ReplaceMDL(a,b) GlobalHelperFunctions.ReplaceFile("resource\\gd_PC\\" a ".prs", "resource\\gd_PC\\" b ".prs");
#define ReplacePAK(a,b) GlobalHelperFunctions.ReplaceFile("resource\\gd_PC\\PRS\\" a ".pak", "resource\\gd_PC\\PRS\\" b ".pak");
#define ReplaceFILE(a,b) GlobalHelperFunctions.ReplaceFile("resource\\gd_PC\\" a, "resource\\gd_PC\\" b);

struct EGC_CONFIG
{
	std::string sonic;
	std::string sonicalt;
	std::string shadow;
	std::string shadowalt;
	std::string amy;
	bool hammer;
	std::string metal;

	std::string mech_tails;
	std::string mech_eggman;
	std::string eggman_alt;
	std::string chaowalker;
	std::string darkwalker;

	std::string knuckles;
	std::string knucklesalt;
	std::string rouge;
	std::string rougealt;
	std::string rougeanm;
	std::string tikal;
	std::string tikalanm;
	std::string chaos;

	std::string miles;
	std::string eggman;

	bool menu;
	bool karts;
};

extern std::string pathGlobal;

extern HMODULE globaldll;;



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

// This was salvaged from the DC Chars repo.
#define FindModel(file) new ModelInfo(std::string(pathGlobal) + "\\Assets\\" file);
#define ReplaceSingleTex(gvm, gvr, folder, name, index, x, y) GlobalHelperFunctions.ReplaceTexture(gvm, gvr, (std::string(path) + "\\Assets\\" folder "\\" name ".png").c_str(), index, x, y)

bool isActive(std::string input);
void InitSonic();
void InitShadow();
void InitAmy();
void InitMetal();

void InitTails();
void InitEggman();
void InitChaoWalker();
void InitDarkChaoWalker();

void InitKnuckles();
void InitRouge();
void InitTikal();
void InitChaos0();

void InitBattleMenu();
void InitKarts();