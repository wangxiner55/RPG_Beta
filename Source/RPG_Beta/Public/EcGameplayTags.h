// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
/**
 * 
 */
struct FEcGameplayTags
{
public:

	static const FEcGameplayTags& Get() { return GameplayTags; }

	static void InitializeNativeGameplayTags();


/*
*	Attributes
*/


	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;

	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;

	// Resistance Of Damage
	FGameplayTag Attributes_Resistance_Fire;
	FGameplayTag Attributes_Resistance_Lightning;
	FGameplayTag Attributes_Resistance_Arcane;
	FGameplayTag Attributes_Resistance_Physical;

/*
*	Input Bind
*/
	FGameplayTag InputTag_Shift;
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;

/*
*	Attack
*/
	FGameplayTag Attack_Damage;
	FGameplayTag Attack_HitReact;

	//Damage Type
	FGameplayTag Attack_Damage_Fire;
	FGameplayTag Attack_Damage_Lightning;
	FGameplayTag Attack_Damage_Arcane;
	FGameplayTag Attack_Damage_Physical;

	


	TMap<FGameplayTag, FGameplayTag> DamageTypesToResistances;

/*
*	Game Effect Status 
*/
	FGameplayTag Status_Stun;						//��ѣ�Σ�			: ��ɫ�޷��ƶ���������ʩ�ż��ܻ�ʹ����Ʒ��
	FGameplayTag Status_Imprison;					//��������			: ��ɫ�޷��ƶ��������Խ��й�����ʩ�ż��ܡ�
	FGameplayTag Status_Disarm;						//����е��			����ɫ�޷����й������������ƶ���ʩ�ż��ܡ�
	FGameplayTag Status_Airborne;					//�����ɣ�			: ��ɫ�����ɵ����У��޷��ƶ���������ʩ�ż��ܡ�
	FGameplayTag Status_Blind;						//����ä��			����ɫ����ͨ������һЩ���ܻ�ʧЧ��
	FGameplayTag Status_Cripple;					//��������			����ɫ�Ĺ����ٶȱ����͡�
	FGameplayTag Status_ForcedAction;				//��ǿ���ж���		����ɫ���Ƚ���ĳ���ж�����Berserk���񱩣���Charm���Ȼ󣩡�Fear/Flee���־�/���ܣ���Taunt��������
	FGameplayTag Status_Nearsight;					//����Ұ���ޣ�		����ɫ����Ұ������Ƚ��͡�
	FGameplayTag Status_Silence;					//����Ĭ��			����ɫ�޷�ʩ�ż��ܡ�
	FGameplayTag Status_Drowsy;						//����˯��			����ɫ�ڻ�˯״̬���ƶ��ٶȽ��ͣ���˯���������˯��״̬���޷������κβ�����
	FGameplayTag Status_Slow;						//�����٣�			����ɫ���ƶ��ٶȱ����͡�
	FGameplayTag Status_Snare;						//������			����ɫ�޷��ƶ��������Թ�����ʩ�ż��ܡ�
	FGameplayTag Status_Stasis;						//��ͣ�ͣ�			����ɫ�޷������κβ�������Ҳ�޷���������ʩ�ż��ܡ�
	FGameplayTag Status_Suspension;					//��������			����ɫ�޷��ƶ���������ʩ�ż��ܡ�
	FGameplayTag Status_Suppression;				//��ѹ�ƣ�			����ɫ�޷��ƶ���������ʩ�ż��ܣ����Ҵ󲿷־���Ч���޷����ѹ��״̬��

protected:

private:

	static FEcGameplayTags GameplayTags;
};
