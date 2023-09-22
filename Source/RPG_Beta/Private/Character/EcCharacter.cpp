// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EcCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/EcPlayerController.h"
#include "Player/EcPlayerState.h"
#include "UI/HUD/EcHUD.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"
#include "AbilitySystem/EcAbilitySystemBlueprintLibrary.h"

AEcCharacter::AEcCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AEcCharacter::BeginPlay()
{
	Super::BeginPlay();
}



/*
*	Possess
*/
void AEcCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
	AddCharacterAbilities();

}

void AEcCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
	
}


/*
*	GAS Module
*/

//Initialization of each ASC module
void AEcCharacter::InitAbilityActorInfo()
{

	AEcPlayerState* EcPlayerState = GetPlayerState<AEcPlayerState>();
	check(EcPlayerState);
	EcPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(EcPlayerState, this);
	AbilitySystemComponent = EcPlayerState->GetAbilitySystemComponent();
	Cast<UEcAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	
	AttributeSet = EcPlayerState->GetAttributeSet();
	InitializeDefaultAttributes();

	if (AEcPlayerController* EcPlayerController = Cast<AEcPlayerController>(GetController()))
	{
		AEcHUD* EcHUD = Cast<AEcHUD>(EcPlayerController->GetHUD());
		if (EcHUD)
		{
			EcHUD->InitOverlay(EcPlayerController, EcPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

	
}

/*
*	Actor Info
*/
int32 AEcCharacter::GetPlayerLevel()
{
	const AEcPlayerState* EcPlayerState = GetPlayerState<AEcPlayerState>();
	check(EcPlayerState);
	return EcPlayerState->GetPlayerLevel();

}

