// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "EcCharacterBase.generated.h"



class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class RPG_BETA_API AEcCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEcCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	FORCEINLINE UAttributeSet* GetAttributeSet() const{ return AttributeSet; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
		TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
		TObjectPtr<UAttributeSet> AttributeSet;


	virtual void InitAbilityActorInfo();

public:	


};
