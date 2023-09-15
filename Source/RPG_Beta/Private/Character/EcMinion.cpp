// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EcMinion.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"
#include "AbilitySystem/EcAttributeSet.h"


AEcMinion::AEcMinion()
{
/*
*  Base Components Info Set
*/
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

/*
*	GAS Module
*/
	AbilitySystemComponent = CreateDefaultSubobject<UEcAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	//	AS   Binding the AS we created to the gas system
	AttributeSet = CreateDefaultSubobject<UEcAttributeSet>("AttributeSet");
}

void AEcMinion::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}


/*
*  Interface Implement
*/
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


/*
*	Base Actor Info
*/
int32 AEcMinion::GetPlayerLevel()
{
	return Level;
}


/*
* 
*	GAS Module
* 
*/
void AEcMinion::InitAbilityActorInfo()
{
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UEcAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

	InitializeDefaultAttributes();
}
