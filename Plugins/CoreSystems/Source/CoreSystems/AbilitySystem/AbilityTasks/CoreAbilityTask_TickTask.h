// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "CoreAbilityTask_TickTask.generated.h"

DECLARE_DELEGATE_OneParam(FOnTickTaskDelegate, float);

/**
 * 
 */
UCLASS()
class CORESYSTEMS_API UCoreAbilityTask_TickTask : public UAbilityTask
{
	GENERATED_BODY()

	UCoreAbilityTask_TickTask();

	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;
	virtual void OnDestroy(bool bInOwnerFinished) override;

	float LastTickTime;

public:
	float TickInterval;
	FOnTickTaskDelegate OnTick;
};
