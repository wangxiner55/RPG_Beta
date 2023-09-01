// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/EcOverlayWidgetController.h"
#include "AbilitySystem/EcAttributeSet.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"



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
		.AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
	);

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(EcAttributeSet->GetMaxHealthAttribute())
		.AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
	);

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(EcAttributeSet->GetManaAttribute())
		.AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
	);

	AbilitySystemComponent
		->GetGameplayAttributeValueChangeDelegate(EcAttributeSet->GetMaxManaAttribute())
		.AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);
			}
	);

	Cast<UEcAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag tag : AssetTags)
			{

				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (tag.MatchesTag(MessageTag))
				{
					FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}

				GEngine->AddOnScreenDebugMessage(-1, 8.0, FColor::Blue, "Hight");

				
			}
		}
	);
}

