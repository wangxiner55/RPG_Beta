// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "EcAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcAssetManager : public UAssetManager
{
	GENERATED_BODY()
	

public:

	static UEcAssetManager& Get();


protected:

	virtual void StartInitialLoading() override;
};
