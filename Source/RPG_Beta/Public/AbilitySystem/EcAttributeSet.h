// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"
#include "EcAttributeSet.generated.h"



#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
		UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
		AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
		AController* SourceController = nullptr;

	UPROPERTY()
		ACharacter* SourceCharacter = nullptr;


	UPROPERTY()
		UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
		AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
		AController* TargetController = nullptr;

	UPROPERTY()
		ACharacter* TargetCharacter = nullptr;

};

template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;
/**
 * 
 */
UCLASS()
class RPG_BETA_API UEcAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	

public:
	UEcAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray< class FLifetimeProperty >& OutLifetimeProps) const;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;


	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;


	/*
	* Secondary Attributes
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Primary Attributes")
		FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Primary Attributes")
		FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, ArmorPenetration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Primary Attributes")
		FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, BlockChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Primary Attributes")
		FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, CriticalHitChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Primary Attributes")
		FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, CriticalHitDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "Primary Attributes")
		FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, CriticalHitResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Primary Attributes")
		FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, HealthRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Primary Attributes")
		FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, ManaRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
		FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, MaxHealth);


	/*
	* Primary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
		FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
		FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, Vigor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
		FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, Resilience);




	/*
	*Vital Attributes
	*/
	UPROPERTY(BlueprintReadOnly ,ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, Mana);



/*
*	Meta Attributes
*/
	UPROPERTY(BlueprintReadOnly, Category = "Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UEcAttributeSet, IncomingDamage);
	


/*
* 
*	Rep
* 
*/


	/*
	* Primary Attributes Rep
	*/
	UFUNCTION()
		void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;


	UFUNCTION()
		void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
		void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
		void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	/*
	*Vital Attributes Rep
	*/
	UFUNCTION()
		void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
		void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
		void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
		void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	/*
	* Secondary Attributes
	*/

	UFUNCTION()
		void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;

	UFUNCTION()
		void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

	UFUNCTION()
		void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	UFUNCTION()
		void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	UFUNCTION()
		void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
		void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
		void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
		void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;


private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;

	void ShowDamageTextWidget(const FEffectProperties& Props, float Damage);
};
