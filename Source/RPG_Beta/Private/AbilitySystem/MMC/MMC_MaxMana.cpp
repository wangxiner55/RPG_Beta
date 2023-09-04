// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxMana.h"
#include "AbilitySystem/EcAttributeSet.h"
#include "Interaction/CombatInterface.h"




UMMC_MaxMana::UMMC_MaxMana()
{
	InteDef.AttributeToCapture = UEcAttributeSet::GetIntelligenceAttribute();
	InteDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	InteDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(InteDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvalutionParameters;
	EvalutionParameters.SourceTags = SourceTags;
	EvalutionParameters.TargetTags = TargetTags;

	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(InteDef, Spec, EvalutionParameters, Intelligence);

	Intelligence = FMath::Max<float>(Intelligence, 0.f);

	ICombatInterface* Interface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());

	const int32 PlayerLevel = Interface->GetPlayerLevel();

	return 80.f + 2.5f * Intelligence + 10.f * PlayerLevel;
}
