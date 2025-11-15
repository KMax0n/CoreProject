// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilityTasks/CoreAbilityTask_TickTask.h"

#include "CoreGameplayAbility.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCoreAbilitySystem, Log, All);

/**
 * 
 */
UCLASS()
class CORESYSTEMS_API UCoreGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

	UCoreGameplayAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	void TickAbility(float DeltaTime);
	void RunTickTask();
	TObjectPtr<UCoreAbilityTask_TickTask> TickTask;
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Ability", meta = (DisplayName = "OnGiveAbility"))
	void K2_OnGiveAbility();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability", meta = (DisplayName = "AbilityTick"))
	void K2_AbilityTick(float DeltaTime);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	bool bTickOnlyWhileActive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	float AbilityTickInterval;
};
