// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreSystems/InstancedActions/InstancedEvaluator.h"

#include "InstancedEvaluator_MeleeTarget.generated.h"

/**
 * 
 */
UCLASS()
class MELEESYSTEM_API UInstancedEvaluator_MeleeTarget : public UInstancedEvaluator
{
	GENERATED_BODY()

public:
	virtual float Evaluate(AActor* ContextActor, AActor* TargetActor);

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Target")
	AActor* TargetCandidate;	
};
