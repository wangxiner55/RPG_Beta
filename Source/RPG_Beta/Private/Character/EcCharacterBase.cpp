// Fill out your copyright notice in the Description page of Project Settings.


#include "../../Public/Character/EcCharacterBase.h"
#include "AbilitySystem/EcAbilitySystemComponent.h"
#include "AbilitySystem/EcAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "../RPG_Beta.h"
#include "Components/WidgetComponent.h"
#include "AbilitySystem/EcAttributeSet.h"
#include "EcGameplayTags.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/EcAbilitySystemBlueprintLibrary.h"

// Sets default values
AEcCharacterBase::AEcCharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;

	// Base Set
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile, ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);

	// Weapon
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	// UserWidgetBar
	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());
}

UAnimMontage* AEcCharacterBase::GetHitReactMontage_Implementation()
{
	return HitReactMontage;
}

void AEcCharacterBase::Die()
{
	if (Weapon)
	{
		Weapon->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld, true));
	}
	MulticastHandleDeath();
}

void AEcCharacterBase::Dissolve()
{
	if (IsValid(DissolveMaterialInstance))
	{
		UMaterialInstanceDynamic* DynamicMatInst = UMaterialInstanceDynamic::Create(DissolveMaterialInstance, this);
		GetMesh()->SetMaterial(0, DynamicMatInst);
		StartDissolveTimeline(DynamicMatInst);
	}
	if (IsValid(WeaponDissolveMaterialInstance))
	{
		UMaterialInstanceDynamic* DynamicMatInst = UMaterialInstanceDynamic::Create(WeaponDissolveMaterialInstance, this);
		Weapon->SetMaterial(0, DynamicMatInst);
		StartWeaponDissolveTimeline(DynamicMatInst);
	}
}

void AEcCharacterBase::MulticastHandleDeath_Implementation()
{
	if (Weapon)
	{
		Weapon->SetSimulatePhysics(true);
		Weapon->SetEnableGravity(true);
		Weapon->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	}

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetEnableGravity(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	Dissolve();
}

void AEcCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
	UEcAbilitySystemBlueprintLibrary::GiveStartupAbilities(this, GetAbilitySystemComponent());

/*
*	Health Bar       Widget Controller Value Bind Call Back
*/

	if (GetAttributeSet() == nullptr) return;
	if (UEcUserWidget* EcUserWidget = Cast<UEcUserWidget>(HealthBar->GetUserWidgetObject()))
	{
		EcUserWidget->SetWidgetController(this);
	}

	UEcAttributeSet* EcAS = CastChecked<UEcAttributeSet>(GetAttributeSet());
	if (EcAS)
	{
		//Updata Value 
		GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(EcAS->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);
		GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(EcAS->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);

		AbilitySystemComponent->RegisterGameplayTagEvent(FEcGameplayTags::Get().Attack_HitReact, EGameplayTagEventType::AnyCountChange)
			.AddUObject(this, &AEcCharacterBase::HitReactTagChanged);

		// Initialize Value
		OnHealthChanged.Broadcast(EcAS->GetHealth());
		OnMaxHealthChanged.Broadcast(EcAS->GetMaxHealth());
	}

}


/*
*  Interface Impact
*/

FVector AEcCharacterBase::GetCombatSocketLocation()
{
	switch (SpawnMode)
	{
	case ESpawnMode::FromWeapon: return Weapon->GetSocketLocation(WeaponTipSocketName);
		break;
	case ESpawnMode::FromSelf: return GetMesh()->GetSocketLocation(WeaponTipSocketName);
		break;
	default: return GetMesh()->GetSocketLocation(WeaponTipSocketName);
		break;
	}
	
}

/*
* 
*	GAS Module
* 
*/


// ASC Module
UAbilitySystemComponent* AEcCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


/*
*  GE Module
*/

// Initialition ASes By GE
void AEcCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.0f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.0f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.0f);
}
// Initialition AS By GE
void AEcCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffect, float PlayerLevel) const
{
	check(IsValid(GetAbilitySystemComponent()));
	//check(GameplayEffect);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffect, PlayerLevel, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}


/*
*  GA Module
*/
void AEcCharacterBase::AddCharacterAbilities()
{
	UEcAbilitySystemComponent* ASC = Cast<UEcAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	ASC->AddCharacterAbilities(StarupAbilities);
}


/*
*	GT
*/
void AEcCharacterBase::HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	bHitReacting = NewCount > 0;
	GetCharacterMovement()->MaxWalkSpeed = bHitReacting ? 0.f : BaseWalkSpeed;
}

void AEcCharacterBase::InitAbilityActorInfo()
{
}
