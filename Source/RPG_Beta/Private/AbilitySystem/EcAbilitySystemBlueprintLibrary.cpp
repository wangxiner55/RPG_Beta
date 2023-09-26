// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/EcAbilitySystemBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/EcHUD.h"
#include "UI/WidgetController/EcOverlayWidgetController.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "Player/EcPlayerState.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"
#include "Game/EcGameModeBase.h"
#include "EcAbilityTypes.h"
#include "AbilitySystemComponent.h"


/*
*	Widget
*/

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

/*
*	Character
*/

void UEcAbilitySystemBlueprintLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC)
{
	UCharacterClassInfo* CharacterClassInfo = GetCharacterClassInfo(WorldContextObject);

	AActor* AvatarActor = ASC->GetAvatarActor();

	FCharacterClassDefaultInfo ClassDefaultInfo = CharacterClassInfo->GetClassDefaultInfo(CharacterClass);

	check(ClassDefaultInfo.PrimaryAttributes);
	FGameplayEffectContextHandle PrimaryAttributeContextHandle = ASC->MakeEffectContext();
	PrimaryAttributeContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle PrimaryAttributesSpecHandle = ASC->MakeOutgoingSpec(ClassDefaultInfo.PrimaryAttributes, Level, PrimaryAttributeContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributesSpecHandle.Data.Get());

	FGameplayEffectContextHandle SecondaryAttributeContextHandle = ASC->MakeEffectContext();
	SecondaryAttributeContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle SecondaryAttributesSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->SecondaryAttributes, Level, SecondaryAttributeContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*SecondaryAttributesSpecHandle.Data.Get());

	FGameplayEffectContextHandle VitalAttributeContextHandle = ASC->MakeEffectContext();
	VitalAttributeContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle VitalAttributesSpecHandle = ASC->MakeOutgoingSpec(CharacterClassInfo->VitalAttributes, Level, VitalAttributeContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*VitalAttributesSpecHandle.Data.Get());

}

void UEcAbilitySystemBlueprintLibrary::GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC)
{
	
	if (ASC == nullptr) return;
	UCharacterClassInfo* CharacterClassInfo = GetCharacterClassInfo(WorldContextObject);

	for (TSubclassOf<UGameplayAbility> AbilityClass : CharacterClassInfo->CommonAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		ASC->GiveAbility(AbilitySpec);
	}

}

UCharacterClassInfo* UEcAbilitySystemBlueprintLibrary::GetCharacterClassInfo(const UObject* WorldContextObject)
{
	AEcGameModeBase* GameMode = Cast<AEcGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (GameMode == nullptr) return nullptr;

	return GameMode->CharacterClassInfo;
}

bool UEcAbilitySystemBlueprintLibrary::IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle)
{
	if (const FEcGameplayEffectContext* EcEffectContext = StaticCast<const FEcGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		return EcEffectContext->IsBlockedHit();
	}
	return false;
}

bool UEcAbilitySystemBlueprintLibrary::IsCriticaldHit(const FGameplayEffectContextHandle& EffectContextHandle)
{
	if (const FEcGameplayEffectContext* EcEffectContext = StaticCast<const FEcGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		return EcEffectContext->IsCriticalHit();
	}
	return false;
}

void UEcAbilitySystemBlueprintLibrary::SetIsBlockedHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,  bool bInIsBlockedHit)
{
	if (FEcGameplayEffectContext* EcEffectContext = StaticCast< FEcGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		EcEffectContext->SetIsBlockHit(bInIsBlockedHit);
	}
}

void UEcAbilitySystemBlueprintLibrary::SetIsCriticaldHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,  bool bInIsCriticalHit)
{
	if (FEcGameplayEffectContext* EcEffectContext = StaticCast< FEcGameplayEffectContext*>(EffectContextHandle.Get()))
	{
		EcEffectContext->SetIsCriticalHit(bInIsCriticalHit);
	}
}
