// Fill out your copyright notice in the Description page of Project Settings.



#include "Player/EcPlayerState.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"
#include "AbilitySystem/EcAttributeSet.h"


AEcPlayerState::AEcPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UEcAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	AttributeSet = CreateDefaultSubobject<UEcAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AEcPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
