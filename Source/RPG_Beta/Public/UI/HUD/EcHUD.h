// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "../WidgetController/AttributeMenuWidgetController.h"
#include "EcHUD.generated.h"


class UEcUserWidget;
class UEcOverlayWidgetController;
class UAbilitySystemComponent;
class UAttributeSet;
class UAttributeMenuWidgetController;
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class RPG_BETA_API AEcHUD : public AHUD
{
	GENERATED_BODY()
	


public:


	UEcOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:


private:

	UPROPERTY()
		TObjectPtr<UEcUserWidget> OverlayWidget;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UEcUserWidget> OverlayWidgetClass;



	UPROPERTY()
		TObjectPtr<UEcOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UEcOverlayWidgetController> OverlayWidgetControllerClass;



	UPROPERTY()
		TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};
