// Fill out your copyright notice in the Description page of Project Settings.


#include "EcAssetManager.h"
#include "EcGameplayTags.h"
#include "AbilitySystemGlobals.h"

UEcAssetManager& UEcAssetManager::Get()
{
	check(GEngine);

	UEcAssetManager* EcAssetManager = Cast<UEcAssetManager>(GEngine->AssetManager);
	return *EcAssetManager;
}


void UEcAssetManager::StartInitialLoading()
{

	Super::StartInitialLoading();

	FEcGameplayTags::InitializeNativeGameplayTags();

	UAbilitySystemGlobals::Get().InitGlobalData();
}
