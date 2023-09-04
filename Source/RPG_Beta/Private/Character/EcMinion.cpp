// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EcMinion.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"
#include "AbilitySystem/EcAttributeSet.h"


AEcMinion::AEcMinion()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	AbilitySystemComponent = CreateDefaultSubobject<UEcAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UEcAttributeSet>("AttributeSet");
}

void AEcMinion::HighlightActor()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
}

void AEcMinion::UnHighlightActor()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
}

int32 AEcMinion::GetPlayerLevel()
{
	return Level;
}

void AEcMinion::BeginPlay()
{
	Super::BeginPlay();

	


}

void AEcMinion::InitAbilityActorInfo()
{
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UEcAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
