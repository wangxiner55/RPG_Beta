// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "EcInputConfig.generated.h"

USTRUCT(BlueprintType)
struct FEcInputAction
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
		const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
		FGameplayTag InputTag = FGameplayTag();
	
};


/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcInputConfig : public UDataAsset
{
	GENERATED_BODY()
	

public:

	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false);


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FEcInputAction> AbilityInputActions;
};
