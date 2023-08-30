// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/EcHUD.h"
#include "UI/Widget/EcUserWidget.h"
#include "UI/WidgetController/EcOverlayWidgetController.h"

UEcOverlayWidgetController* AEcHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UEcOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AEcHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Ovelay Widget Class Uninitialized"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class Uninitialized"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UEcUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UEcOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}
