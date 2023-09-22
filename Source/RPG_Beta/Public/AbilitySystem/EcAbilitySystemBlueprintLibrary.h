// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/CharacterClassInfo.h"
#include "EcAbilitySystemBlueprintLibrary.generated.h"


class UAbilitySystemComponent;
class UEcOverlayWidgetController;
class UAttributeMenuWidgetController;
/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcAbilitySystemBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "EcAbilitySystemLibrary|WidgetController")
		static UEcOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "EcAbilitySystemLibrary|WidgetController")
		static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "EcAbilitySystemLibrary|CharacterClassDefaults")
		static void InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC);
	
	UFUNCTION(BlueprintCallable, Category = "EcAbilitySystemLibrary|CharacterClassDefaults")
		static void GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC);

	UFUNCTION(BlueprintCallable, Category = "EcAbilitySystemLibrary|CharacterClassDefaults")
		static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);

};
