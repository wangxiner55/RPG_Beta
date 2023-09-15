// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/EcCharacterBase.h"
#include "../Interaction/MinionInterface.h"
#include "EcMinion.generated.h"


/**
 * 
 */
UCLASS()
class RPG_BETA_API AEcMinion : public AEcCharacterBase , public IMinionInterface 
{
	GENERATED_BODY()
	

public:
	AEcMinion();


/*
*	Interface Implement
*/

	//Minion Interface

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;


	//Combat Interface

	virtual int32 GetPlayerLevel() override;


protected:

	virtual void BeginPlay() override;

/*
*	GAS Module
*/
	//Initialization bind of each GAS module
	virtual void InitAbilityActorInfo() override;

public:

/*
*	Interface Implement
*/


	//Minion Interface
	UPROPERTY(BlueprintReadOnly)
		bool bHighlighted = false;

	//Combat Interface
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
		int32 Level = 1;

};
