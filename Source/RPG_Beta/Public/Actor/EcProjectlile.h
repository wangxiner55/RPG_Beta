// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "EcProjectlile.generated.h"

class UGameplayEffect;
class UNiagaraSystem;
class USphereComponent;
class UProjectileMovementComponent;
struct FGameplayEffectSpecHandle;

UCLASS()
class RPG_BETA_API AEcProjectlile : public AActor
{
	GENERATED_BODY()
	
public:	

	AEcProjectlile();

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(BlueprintReadWrite, meta=(ExposeOnSpawn = true))
		FGameplayEffectSpecHandle DamageEffectSpecHandle;


protected:

	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:

	bool bHit = false;
	UPROPERTY(EditDefaultsOnly)
		float LifeSpan = 15.f;

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UNiagaraSystem> ImpactEffect;


	UPROPERTY(EditAnywhere)
		TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere)
		TObjectPtr<USoundBase> LoopSound;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UAudioComponent> LoopingSoundComponent;

};
