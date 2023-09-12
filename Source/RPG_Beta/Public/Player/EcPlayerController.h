// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Input/EcInputComponent.h"
#include "NavigationSystem.h"
#include "EcPlayerController.generated.h"

/**
 * 
 */


class UEcAbilitySystemComponent;
struct FGameplayTag;
class UEcInputConfig;
class UInputMappingContext;
class USplineComponent;
class UInputAction;
class IMinionInterface;
struct FInputActionValue;


UCLASS()
class RPG_BETA_API AEcPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AEcPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TObjectPtr<USplineComponent> Spline;

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> EcContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	IMinionInterface* LastActor;
	IMinionInterface* ThisActor;
	FHitResult CursorHit;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);


	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UEcInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UEcAbilitySystemComponent> EcAbilitySystemComponent;

	UEcAbilitySystemComponent* GetASC();

	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRuning = false;

	UPROPERTY(EditDefaultsOnly)
		float AutoRunAcceptanceRadius = 50.f;

	

	bool bTargeting = false;

	void AutoRun();








	TObjectPtr<UInputComponent> PlayerInputComponent;

	UFUNCTION(BlueprintCallable)
	UInputComponent* GetInputComponent();
};
