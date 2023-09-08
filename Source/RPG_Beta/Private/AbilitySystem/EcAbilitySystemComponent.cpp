// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/EcAbilitySystemComponent.h"

void UEcAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UEcAbilitySystemComponent::EffectAppliced);
}

void UEcAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StarupAbilities)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : StarupAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		GiveAbility(AbilitySpec);
	}
}

void UEcAbilitySystemComponent::EffectAppliced(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	//EffectSpec.GetAllAssetTags(TagContainer);
	EffectSpec.GetAllGrantedTags(TagContainer);
	EffectAssetTags.Broadcast(TagContainer);
}
