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
}
