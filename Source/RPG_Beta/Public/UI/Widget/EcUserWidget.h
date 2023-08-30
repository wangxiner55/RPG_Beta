// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EcUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TObjectPtr<UObject> WidgetController;


protected:

	UFUNCTION(BlueprintImplementableEvent)
		void WidgetControllerSet();
};
