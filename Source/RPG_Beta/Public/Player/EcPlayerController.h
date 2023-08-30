// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EcPlayerController.generated.h"

/**
 * 
 */

class UInputMappingContext;
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
};
