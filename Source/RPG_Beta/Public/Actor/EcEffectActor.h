// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "EcEffectActor.generated.h"



class UGameplayEffect;
class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	NoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovePolicy : uint8
{
	RemoveOnEndOverlap,
	NoNotRemove
};



UCLASS()
class RPG_BETA_API AEcEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AEcEffectActor();

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);
	
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::NoNotApply;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::NoNotApply;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::NoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	EEffectRemovePolicy InfiniteEffectRemovePolicy = EEffectRemovePolicy::RemoveOnEndOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appliced Effects")
	float ActorLevel = 1.0f;



	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActivedEffectHandles;
};
