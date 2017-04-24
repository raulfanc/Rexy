#include "Annie.h"


void Annie::Load_Menu()
{

	MainMenu = GPluginSDK->AddMenu("HeavenStrikeAnnie");

	HarassMenu = MainMenu->AddMenu("Harass");
	{
		HarassQ = HarassMenu->CheckBox("use Q ", true);
		HarassW = HarassMenu->CheckBox("use W ", true);
		HarassMana = HarassMenu->AddInteger("harass mana slider", 0, 100, 40);
	}

	LaneclearMenu = MainMenu->AddMenu("LaneClear");
	{
		LaneclearQ = LaneclearMenu->CheckBox("use Q", true);
		LaneclearW = LaneclearMenu->CheckBox("use W", true);
		LaneclearMana = LaneclearMenu->AddInteger("harass mana slider", 0, 100, 40);
	}

	JungleclearMenu = MainMenu->AddMenu("JungleClear");
	{
		JungleclearQ = JungleclearMenu->CheckBox("use Q", true);
		JungleclearW = JungleclearMenu->CheckBox("use W", true);
		JungleclearE = JungleclearMenu->CheckBox("use E", true);
		JungleClearMana = JungleclearMenu->AddInteger("harass mana slider", 0, 100, 40);
	}

	ComboMenu = MainMenu->AddMenu("Combo");
	{
		ComboQ = ComboMenu->CheckBox("use Q", true);
		ComboW = ComboMenu->CheckBox("use W", true);
		ComboE = ComboMenu->CheckBox("use E", true);
		ComboR = ComboMenu->CheckBox("use R", true);
	}
}


void Annie::Load_Spells()
{
	Q = GPluginSDK->CreateSpell2(kSlotQ, kTargetCast, false, false, kCollidesWithYasuoWall);
	Q->SetOverrideRange(625.f);

	W = GPluginSDK->CreateSpell2(kSlotW, kConeCast, false, true, 0);
	W->SetSkillshot(0.25f, 50.f, FLT_MAX, 560.f);

	E = GPluginSDK->CreateSpell2(kSlotE, kTargetCast, false, false, 0);

	R = GPluginSDK->CreateSpell2(kSlotR, kCircleCast, false, true, 0);
	R->SetSkillshot(0.25f, 250.f, FLT_MAX, 600.f);
}


void Annie::Combo()
{
	Target = GTargetSelector->GetFocusedTarget();

	if (Target == nullptr || !Target->IsValidTarget(GEntityList->Player(), Q->Range()) || Target->IsDead())
		return;

	if (Q->IsReady() && ComboQ->Enabled())
	{
		Q->CastOnUnit(Target);
	}

	if (W->IsReady() && ComboW->Enabled() && Target->IsValidTarget(GEntityList->Player(), W->Range()))
	{
		W->CastOnTarget(Target, 5);
	}

	if (R->IsReady() && ComboR->Enabled())
	{
		if (Target->HealthPercent() <= 40)
			R->CastOnTarget(Target, 5);
		else
			R->CastOnTargetAoE(Target, 2, 5);
	}
}


void Annie::Harass()
{
	Target = GTargetSelector->GetFocusedTarget();

	if (Target->IsDead() || Target == nullptr)
	{
		return;
	}
	if (Q->IsReady() && ComboQ->Enabled() && Target->IsValidTarget(GEntityList->Player(), Q->Range()))
	{
		Q->CastOnUnit(Target);
	}
}

void Annie::LaneClear()
{

}

void Annie::LastHit()
{

}