// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InstancedActionsData.h"

#include "InstancedEvaluator.generated.h"

UCLASS(DefaultToInstanced, Blueprintable)
class CORESYSTEMS_API UInstancedEvaluator : public UObject
{
	GENERATED_BODY()
	
protected:
	UInstancedEvaluator();

	virtual float Evaluate(AActor* ContextActor);

	UFUNCTION(BlueprintImplementableEvent)
	float K2_Evaluate();

	UPROPERTY(BlueprintReadOnly)
	AActor* Context;

public:
	UPROPERTY(EditDefaultsOnly)
	bool bEnable;

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<EEnumEvaluationMode::Type> EvaluationMode;
};
