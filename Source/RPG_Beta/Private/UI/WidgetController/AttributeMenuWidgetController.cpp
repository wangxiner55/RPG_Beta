// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/EcAttributeSet.h"
#include "EcGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UEcAttributeSet* AS = Cast<UEcAttributeSet>(AttributeSet);

	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes) 
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda
		(
			[this, Pair, AS](const FOnAttributeChangeData& Data)
			{
				BroadcastAttributeInfo(Pair.Key, Pair.Value());
			}
		);
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
	FEcAttributeInfo Info = AttributeInfo->FindAttributeForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoSignature.Broadcast(Info);
}


void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UEcAttributeSet* AS = Cast<UEcAttributeSet>(AttributeSet);

	check(AttributeInfo);


	for (auto& Pair : AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

