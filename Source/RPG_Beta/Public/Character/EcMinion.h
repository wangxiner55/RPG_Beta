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

	/* Minion Interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* End Minion Interface*/

	/* Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/* Combat Interface*/

protected:

	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;

public:


	UPROPERTY(BlueprintReadOnly)
		bool bHighlighted = false;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
		int32 Level = 1;

};
