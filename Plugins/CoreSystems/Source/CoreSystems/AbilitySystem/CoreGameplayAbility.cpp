// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreGameplayAbility.h"

DEFINE_LOG_CATEGORY(LogCoreAbilitySystem);

UCoreGameplayAbility::UCoreGameplayAbility()
{
	bTickOnlyWhileActive = true;
	AbilityTickInterval = 0.0f;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor; 
}

void UCoreGameplayAbility::RunTickTask()
{
	TickTask = UAbilityTask::NewAbilityTask<UCoreAbilityTask_TickTask>(this);
	TickTask->TickInterval = AbilityTickInterval;
	TickTask->OnTick.BindUObject(this, &UCoreGameplayAbility::TickAbility);
	TickTask->ReadyForActivation();
}

void UCoreGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (bTickOnlyWhileActive)
	{
		RunTickTask();
	}

	UE_LOG(LogCoreAbilitySystem, Log , TEXT("%s ActivateAbility"), *GetName());
}

void UCoreGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (!bTickOnlyWhileActive)
	{
		RunTickTask();
	}
	
	K2_OnGiveAbility();
}

void UCoreGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (bTickOnlyWhileActive)
	{
		TickTask->OnTick.Unbind();
		TickTask->EndTask();
	}
}

void UCoreGameplayAbility::TickAbility(float DeltaTime)
{
	K2_AbilityTick(DeltaTime);
}
