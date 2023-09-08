// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AttributeInfo.h"

FEcAttributeInfo UAttributeInfo::FindAttributeForTag(const FGameplayTag& AttributeTag, bool bLogNotFound)
{
    for (const FEcAttributeInfo& Info : AttributeInformation)
    {
        if (Info.AttributeTag.MatchesTag(AttributeTag))
        {
            return Info;
        }
    }
    if (bLogNotFound)
    {
        UE_LOG(LogTemp,Error,TEXT("Can`t find Info For AttributeTag [%s] On AttributeInfo [%s]"),*AttributeTag.ToString(),*GetNameSafe(this))
    }

    return FEcAttributeInfo();
}
