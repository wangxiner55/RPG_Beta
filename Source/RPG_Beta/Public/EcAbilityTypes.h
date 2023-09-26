#pragma once
#include "GameplayEffectTypes.h"
#include "EcAbilityTypes.generated.h"


USTRUCT(BlueprintType)
struct FEcGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:


	FORCEINLINE bool IsCriticalHit() const { return bIsCriticalHit; }
	FORCEINLINE bool IsBlockedHit() const { return bIsBlockedHit; }

	 void SetIsCriticalHit(bool bInIsCriticalHit) { bIsCriticalHit = bInIsCriticalHit; }
	 void SetIsBlockHit(bool bInIsBlockHit) { bIsBlockedHit = bInIsBlockHit; }

	/** Returns the actual struct used for serialization, subclasses must override this! */
	virtual UScriptStruct* GetScriptStruct() const
	{
		return FGameplayEffectContext::StaticStruct();
	}

	/** Creates a copy of this context, used to duplicate for later modifications */
	virtual FGameplayEffectContext* Duplicate() const
	{
		FGameplayEffectContext* NewContext = new FGameplayEffectContext();
		*NewContext = *this;
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}


	/** Custom serialization, subclasses must override this */
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess);



protected:


	UPROPERTY()
	bool bIsCriticalHit;

	UPROPERTY()
	bool bIsBlockedHit;

};


template<>
struct TStructOpsTypeTraits<FEcGameplayEffectContext> : public TStructOpsTypeTraitsBase2<FEcGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true		// Necessary so that TSharedPtr<FHitResult> Data is copied around
	};
};
