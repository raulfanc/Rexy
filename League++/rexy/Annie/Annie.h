#pragma once
#include "PluginSDK.h"

class Annie
{
public:
	void Load_Menu();

	void Load_Spells();

	void Harass();

	void LaneClear();

	void LastHit();

	void Combo();


	IMenu *MainMenu;
	IMenu *HarassMenu;
	IMenu *LaneclearMenu;
	IMenu *JungleclearMenu;
	IMenu *ComboMenu;
	IMenuOption *HarassQ;
	IMenuOption *HarassW;
	IMenuOption *harassE;
	IMenuOption *LaneclearQ;
	IMenuOption *LaneclearW;
	IMenuOption *laneclearE;
	IMenuOption *JungleclearQ;
	IMenuOption *JungleclearW;
	IMenuOption *JungleclearE;
	IMenuOption *ComboQ;
	IMenuOption *ComboW;
	IMenuOption *ComboE;
	IMenuOption *ComboR;
	IMenuOption *HarassMana;
	IMenuOption *LaneclearMana;
	IMenuOption *JungleClearMana;

	IUnit *Target;

	ISpell2 *Q;
	ISpell2 *W;
	ISpell2 *E;
	ISpell2 *R;

};


