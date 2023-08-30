// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "EcPlayerState.generated.h"



//class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class RPG_BETA_API AEcPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AEcPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	FORCEINLINE UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:


	UPROPERTY()
		TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
		TObjectPtr<UAttributeSet> AttributeSet;
};
