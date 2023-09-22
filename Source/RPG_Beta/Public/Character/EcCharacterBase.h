// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/CombatInterface.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "../UI/WidgetController/EcOverlayWidgetController.h"
#include "EcCharacterBase.generated.h"

class UWidgetComponent;
class UGameplayAbility;
class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
class UAnimMontage;

UENUM(BlueprintType)
enum class ESpawnMode : uint8
{
	FromWeapon,
	FromSelf
};




UCLASS()
class RPG_BETA_API AEcCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	
	AEcCharacterBase();

	UPROPERTY(BlueprintReadOnly, Category = "Hit")
		bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category = "BaseInfo")
		float BaseWalkSpeed = 250.f;


	virtual UAnimMontage* GetHitReactMontage_Implementation() override;



/*
*  Combat
*/


	// Die

	virtual void Die() override;

	UFUNCTION(NetMulticast, Reliable)
		virtual void MulticastHandleDeath();

	UFUNCTION(BlueprintImplementableEvent)
		void StartDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);

	UFUNCTION(BlueprintImplementableEvent)
		void StartWeaponDissolveTimeline(UMaterialInstanceDynamic* DynamicMaterialInstance);


	// Dissolve Effect

	void Dissolve();


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TObjectPtr<UMaterialInstance> DissolveMaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TObjectPtr<UMaterialInstance> WeaponDissolveMaterialInstance;

	

/*
*	Attribute Change Signature
*/

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangeSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangeSignature OnMaxHealthChanged;


/*
* 
*	GAS Module
* 
*/


/*
*	ASC
*/

	//A reflection module must be added for blueprint calls !!!!!!!!
	UFUNCTION(BlueprintCallable)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

/*
*	AS
*/
	FORCEINLINE UAttributeSet* GetAttributeSet() const{ return AttributeSet; }

protected:


	virtual void BeginPlay() override;



/*
*	Character Base Info
*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
		int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
		ECharacterClass CharacterClass = ECharacterClass::Ranger;

	// Attack


	

/*
*	Base Components
*/


	virtual FVector GetCombatSocketLocation() override;


	UPROPERTY(EditAnywhere, Category = "Combat")
		TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TObjectPtr<UWidgetComponent> HealthBar;

	UPROPERTY(EditAnywhere, Category = "Combat")
		FName WeaponTipSocketName;

	UPROPERTY(EditAnywhere, Category = "Combat")
		ESpawnMode SpawnMode = ESpawnMode::FromSelf;


	

/*
* 
*	GAS Module
* 
*/

/*
*	ASC
*/

	//Initialization of each ASC module

	virtual void InitAbilityActorInfo();

	UPROPERTY()
		TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

/*
*	AS
*/

	// Initialize Defaults Attributes
	UFUNCTION()
	virtual void InitializeDefaultAttributes()const;


	UPROPERTY()
		TObjectPtr<UAttributeSet> AttributeSet;

	// GE To Initialization AS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
		TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
		TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
		TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	
/*
*	GE
*/

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffect, float Level) const;
	
	

/*
*	GA
*/

	void AddCharacterAbilities();


/*
*	GT
*/
	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);



private:
	
	UPROPERTY(EditAnywhere, Category = "Hit")
	TObjectPtr<UAnimMontage> HitReactMontage;



/*
*	GA
*/
	UPROPERTY(EditAnyWhere ,Category = "Attributes")
		TArray<TSubclassOf<UGameplayAbility>> StarupAbilities;




};
