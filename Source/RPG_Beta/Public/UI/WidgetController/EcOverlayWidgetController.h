// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/EcWidgetController.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UI/Widget/EcUserWidget.h"
#include "EcOverlayWidgetController.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangeSignature, float, NewValue);



struct FOnAttributeChangeData;



USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UEcUserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;


};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);
/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcOverlayWidgetController : public UEcWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override; 


	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAttributeChangeSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAttributeChangeSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAttributeChangeSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAttributeChangeSignature OnMaxManaChanged;


	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FMessageWidgetRowSignature  MessageWidgetRowDelegate;


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Message Table")
	TObjectPtr<UDataTable> MessageWidgetDataTable;



	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& tag);
};

template<typename T>
inline T* UEcOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& tag)
{
	return DataTable->FindRow<T>(tag.GetTagName(),TEXT(""));
}
