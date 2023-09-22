// Fill out your copyright notice in the Description page of Project Settings.


#include "EcGameplayTags.h"
#include "GameplayTagsManager.h"


FEcGameplayTags FEcGameplayTags::GameplayTags;

void FEcGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.Armor"), 
	 FString("Armor"));

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.ArmorPenetration"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.BlockChance"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.CriticalHitChance"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.CriticalHitResistance"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.HealthRegeneration"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.ManaRegeneration"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.MaxHealth"),
		FString("Armor"));

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.MaxMana"),
		FString("Armor"));


	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Strength"),
		FString("Armor"));

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Intelligence"),
		FString("Armor"));

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Resilience"),
		FString("Armor"));

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Vigor"),
		FString("Armor"));



	/*
	* Input Tags
	*/


	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("InputTag.LMB"),
		FString("Input Tag For Left Mouse Button"));

	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("InputTag.RMB"),
		FString("Input Tag For Right Mouse Button"));

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("InputTag.1"),
		FString("Input Tag For  Key 1"));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("InputTag.2"),
		FString("Input Tag For  Key 2"));

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("InputTag.3"),
		FString("Input Tag For  Key 3"));

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("InputTag.4"),
		FString("Input Tag For  Key 4"));


/*
*	Attack
*/

	GameplayTags.Attack_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attack.Damage"),
		FString("IncomingDamage"));

	GameplayTags.Attack_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attack.HitReact"),
		FString("HitReactMontage"));

	/*
	*	Status
	*/

	GameplayTags.Status_Stun = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.Stun"),
		FString("角色无法移动，攻击，施放技能或使用物品"));

	GameplayTags.Status_Imprison = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.Imprison"),
		FString("角色无法移动，但可以进行攻击和施放技能"));

	GameplayTags.Status_Disarm = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.Disarm"),
		FString("角色无法进行攻击，但可以移动和施放技能"));

	GameplayTags.Status_Airborne = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.Airborne"),
		FString("角色被击飞到空中，无法移动、攻击或施放技能"));

	GameplayTags.Status_Blind = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.Blind"),
		FString("角色的普通攻击和一些技能会失效"));

	GameplayTags.Status_Blind = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.Cripple"),
		FString(""));

	GameplayTags.Status_Blind = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.ForcedAction"),
		FString("角色被迫进行某种行动，如Berserk（狂暴）、Charm（魅惑）、Fear/Flee（恐惧/逃跑）和Taunt（嘲讽）"));

	GameplayTags.Status_Blind = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Status.Nearsight"),
		FString(""));



}
