// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "EcGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()


public:

	UPROPERTY(EditDefaultsOnly, Category = "Input")
		FGameplayTag StartupInputTag;
	

	
	

};
