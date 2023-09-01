// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/EcAttributeSet.h"
#include "AttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"

UEcAttributeSet::UEcAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(100.f);
	InitMaxMana(100.f);
}

void UEcAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UEcAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEcAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEcAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEcAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UEcAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UEcAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}
}

void UEcAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEcAttributeSet, Health, OldHealth);
}

void UEcAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEcAttributeSet, MaxHealth, OldMaxHealth);
}

void UEcAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEcAttributeSet, Mana, OldMana);
}

void UEcAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEcAttributeSet, MaxMana, OldMaxMana);
}

void UEcAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{

	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}
