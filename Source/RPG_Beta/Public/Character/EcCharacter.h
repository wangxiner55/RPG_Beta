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
	

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;


private:
	virtual void InitAbilityActorInfo() override;
};
