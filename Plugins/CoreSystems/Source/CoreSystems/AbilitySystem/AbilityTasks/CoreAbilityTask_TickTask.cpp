// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreAbilityTask_TickTask.h"

UCoreAbilityTask_TickTask::UCoreAbilityTask_TickTask()
{
	TickInterval = 0.0f;
	bTickingTask = true;
}

void UCoreAbilityTask_TickTask::Activate()
{
	Super::Activate();
}

void UCoreAbilityTask_TickTask::TickTask(float DeltaTime)
{
	const float WorldTime = GetWorld()->TimeSeconds;
	
	if (WorldTime >= (LastTickTime + TickInterval))
	{
		LastTickTime = WorldTime;
		OnTick.ExecuteIfBound(DeltaTime);

		Super::TickTask(DeltaTime);
		UE_LOG(LogGameplayTasks, Log, TEXT("TickTask %s with interval %f"), *GetName(), TickInterval);
	}
}

void UCoreAbilityTask_TickTask::OnDestroy(bool bInOwnerFinished)
{
	Super::OnDestroy(bInOwnerFinished);
}
