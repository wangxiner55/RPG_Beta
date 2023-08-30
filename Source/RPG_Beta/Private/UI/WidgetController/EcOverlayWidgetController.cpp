// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/EcOverlayWidgetController.h"
#include "AbilitySystem/EcAttributeSet.h"
#include "GameplayEffectTypes.h"



void UEcOverlayWidgetController::BroadcastInitialValues()
{
	UEcAttributeSet* EcAttributeSet = CastChecked<UEcAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(EcAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(EcAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(EcAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(EcAttributeSet->GetMaxMana());
}

void UEcOverlayWidgetController::BindCallbacksToDependencies()
{

	UEcAttributeSet* EcAttributeSet = CastChecked<UEcAttributeSet>(AttributeSet);
	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(EcAttributeSet->GetHealthAttribute())
		.AddUObject(this, &UEcOverlayWidgetController::HealthChanged);
	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(EcAttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &UEcOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(EcAttributeSet->GetManaAttribute())
		.AddUObject(this, &UEcOverlayWidgetController::ManaChanged);
	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(EcAttributeSet->GetMaxManaAttribute())
		.AddUObject(this, &UEcOverlayWidgetController::MaxManaChanged);

}



void UEcOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UEcOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data)
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UEcOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UEcOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data)
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
