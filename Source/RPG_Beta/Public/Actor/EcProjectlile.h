// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EcProjectlile.generated.h"


class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class RPG_BETA_API AEcProjectlile : public AActor
{
	GENERATED_BODY()
	
public:	

	AEcProjectlile();

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

protected:

	virtual void BeginPlay() override;
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<USphereComponent> Sphere;

};
