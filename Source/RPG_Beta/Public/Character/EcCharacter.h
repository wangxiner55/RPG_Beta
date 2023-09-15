// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/EcCharacterBase.h"
#include "EcCharacter.generated.h"


class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class RPG_BETA_API AEcCharacter : public AEcCharacterBase
{
	GENERATED_BODY()

public:
	AEcCharacter();
	

/*
*	At Server And Client Set possess By
*/
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

/*
*	Interface Implement
*/
	virtual int32 GetPlayerLevel() override;

private:

/*
*	Initialization of each ASC module
*/
	virtual void InitAbilityActorInfo() override;
};
