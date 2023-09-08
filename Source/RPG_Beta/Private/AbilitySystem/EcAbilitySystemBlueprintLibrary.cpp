// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/EcAbilitySystemBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/EcHUD.h"
#include "UI/WidgetController/EcOverlayWidgetController.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "Player/EcPlayerState.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"

UEcOverlayWidgetController* UEcAbilitySystemBlueprintLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AEcHUD* HUD = Cast<AEcHUD>(PC->GetHUD()))
		{
			AEcPlayerState* PS = PC->GetPlayerState<AEcPlayerState>();
			UAttributeSet* AS = PS->GetAttributeSet();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();

			const FWidgetControllerParams WCP(PC, PS, ASC, AS);

			return HUD->GetOverlayWidgetController(WCP);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UEcAbilitySystemBlueprintLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AEcHUD* HUD = Cast<AEcHUD>(PC->GetHUD()))
		{
			AEcPlayerState* PS = PC->GetPlayerState<AEcPlayerState>();
			UAttributeSet* AS = PS->GetAttributeSet();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();

			const FWidgetControllerParams WCP(PC, PS, ASC, AS);

			return HUD->GetAttributeMenuWidgetController(WCP);
		}
	}
	return nullptr;
}
