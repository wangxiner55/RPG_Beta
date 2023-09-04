// Fill out your copyright notice in the Description page of Project Settings.



#include "Player/EcPlayerState.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"
#include "AbilitySystem/EcAttributeSet.h"
#include "Net/UnrealNetwork.h"


AEcPlayerState::AEcPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UEcAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	AttributeSet = CreateDefaultSubobject<UEcAttributeSet>("AttributeSet");
}

void AEcPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEcPlayerState, Level);
}

UAbilitySystemComponent* AEcPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

int32 AEcPlayerState::GetPlayerLevel() const
{
	return Level;
}

void AEcPlayerState::OnRep_Level(int32 OldLevel)
{

}
