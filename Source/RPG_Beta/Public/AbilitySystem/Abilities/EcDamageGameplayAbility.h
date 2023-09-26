// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/EcGameplayAbility.h"
#include "EcDamageGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcDamageGameplayAbility : public UEcGameplayAbility
{
	GENERATED_BODY()
	

public:
	// GE
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TSubclassOf<UGameplayEffect> DamageEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
		TMap<FGameplayTag, FScalableFloat> DamageTypes;

};
