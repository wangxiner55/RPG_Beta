// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EcHUD.generated.h"


class UEcUserWidget;
class UEcOverlayWidgetController;
class UAbilitySystemComponent;
class UAttributeSet;
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class RPG_BETA_API AEcHUD : public AHUD
{
	GENERATED_BODY()
	


public:
	UPROPERTY()
		TObjectPtr<UEcUserWidget> OverlayWidget;

	UEcOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:


private:

	UPROPERTY(EditAnywhere)
		TSubclassOf<UEcUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UEcOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
		TObjectPtr<UEcOverlayWidgetController> OverlayWidgetController;
};
