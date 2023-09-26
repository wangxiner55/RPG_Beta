// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/EcDamageGameplayAbility.h"
#include "EcProjectileSpell.generated.h"



class AEcProjectlile;
/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcProjectileSpell : public UEcDamageGameplayAbility
{
	GENERATED_BODY()
	

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;


/*
*	Projectile
*/
	// Projectile
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<AEcProjectlile> ProjectileClass;

	UFUNCTION(BlueprintCallable, Category = "Projectile")
		void SpawnProjectile(const FVector& ProjectileTargetLocation);

	



};
