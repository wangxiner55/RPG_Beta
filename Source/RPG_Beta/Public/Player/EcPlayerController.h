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

class UDamageWidgetComponent;
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

	UFUNCTION(Client, Reliable)
		void ShowDamageWidget(float DamageValue, ACharacter* TargetCharacter);
protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

/*
*	ASC Module
*/

	UEcAbilitySystemComponent* GetASC();

	UPROPERTY()
		TObjectPtr<UEcAbilitySystemComponent> EcAbilitySystemComponent;
	

/*
*  Action Input Bind
*/


	//context
	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputMappingContext> EcContext;


	// Base Movement Input Bind
	void Move(const FInputActionValue& InputActionValue);

	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> MoveAction;

	// Ability Input Bind
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
		TObjectPtr<UEcInputConfig> InputConfig;


	// Fore Attack Bind
	FORCEINLINE void ShiftPressed() { bShiftKeyDown = true; };
	FORCEINLINE void ShiftReleased() { bShiftKeyDown = false; };

	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> ShiftAction;


/*
*  Curson Move
*/

	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRuning = false;

	UPROPERTY(EditDefaultsOnly)
		float AutoRunAcceptanceRadius = 50.f;

	bool bTargeting = false;

	void AutoRun();


/*
*  Set hit target
*/

	void CursorTrace();

	IMinionInterface* LastActor;
	IMinionInterface* ThisActor;
	FHitResult CursorHit;
	bool bShiftKeyDown = false;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDamageWidgetComponent> DamageTextComponentClass;


/*
*  Debug Out Module
*/


	TObjectPtr<UInputComponent> PlayerInputComponent;

	UFUNCTION(BlueprintCallable)
	UInputComponent* GetInputComponent();
};
