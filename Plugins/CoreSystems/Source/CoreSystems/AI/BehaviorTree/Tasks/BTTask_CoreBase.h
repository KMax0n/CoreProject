// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTask_CoreBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CORESYSTEMS_API UBTTask_CoreBase : public UBTTask_BlueprintBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bInstant;
};
