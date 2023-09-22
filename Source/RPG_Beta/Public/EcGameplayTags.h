// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
/**
 * 
 */
struct FEcGameplayTags
{
public:

	static const FEcGameplayTags& Get() { return GameplayTags; }

	static void InitializeNativeGameplayTags();


/*
*	Attributes
*/


	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;

	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;

/*
*	Input Bind
*/
	FGameplayTag InputTag_Shift;
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;

/*
*	Attack
*/
	FGameplayTag Attack_Damage;
	FGameplayTag Attack_HitReact;

/*
*	Game Effect Status 
*/
	FGameplayTag Status_Stun;						//（眩晕）			: 角色无法移动，攻击，施放技能或使用物品。
	FGameplayTag Status_Imprison;					//（禁锢）			: 角色无法移动，但可以进行攻击和施放技能。
	FGameplayTag Status_Disarm;						//（缴械）			：角色无法进行攻击，但可以移动和施放技能。
	FGameplayTag Status_Airborne;					//（击飞）			: 角色被击飞到空中，无法移动、攻击或施放技能。
	FGameplayTag Status_Blind;						//（致盲）			：角色的普通攻击和一些技能会失效。
	FGameplayTag Status_Cripple;					//（削弱）			：角色的攻击速度被降低。
	FGameplayTag Status_ForcedAction;				//（强制行动）		：角色被迫进行某种行动，如Berserk（狂暴）、Charm（魅惑）、Fear/Flee（恐惧/逃跑）和Taunt（嘲讽）。
	FGameplayTag Status_Nearsight;					//（视野受限）		：角色的视野被大幅度降低。
	FGameplayTag Status_Silence;					//（沉默）			：角色无法施放技能。
	FGameplayTag Status_Drowsy;						//（昏睡）			：角色在昏睡状态下移动速度降低，昏睡结束后进入睡眠状态，无法进行任何操作。
	FGameplayTag Status_Slow;						//（减速）			：角色的移动速度被降低。
	FGameplayTag Status_Snare;						//（定身）			：角色无法移动，但可以攻击和施放技能。
	FGameplayTag Status_Stasis;						//（停滞）			：角色无法进行任何操作，但也无法被攻击或施放技能。
	FGameplayTag Status_Suspension;					//（悬浮）			：角色无法移动、攻击或施放技能。
	FGameplayTag Status_Suppression;				//（压制）			：角色无法移动、攻击或施放技能，并且大部分净化效果无法解除压制状态。

protected:

private:

	static FEcGameplayTags GameplayTags;
};
