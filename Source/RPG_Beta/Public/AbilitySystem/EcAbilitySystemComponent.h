// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "EcAbilitySystemComponent.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, FGameplayTagContainer&);

/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()


public:

	FEffectAssetTags EffectAssetTags;

public:

	void AbilityActorInfoSet();

	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StarupAbilities);

	void EffectAppliced(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
