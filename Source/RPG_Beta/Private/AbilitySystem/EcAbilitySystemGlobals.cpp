// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/EcAbilitySystemGlobals.h"
#include "EcAbilityTypes.h"

FGameplayEffectContext* UEcAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FEcGameplayEffectContext;
}
