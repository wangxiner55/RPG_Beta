// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/EcInputConfig.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

const UInputAction* UEcInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound)
{
	for (const FEcInputAction& Action : AbilityInputActions)
	{
		if(Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound) UE_LOG(LogTemp, Error, TEXT("Can~t find InputAction[%s] from Tag"), *InputTag.ToString(), *GetNameSafe(this));

	return nullptr;
}
