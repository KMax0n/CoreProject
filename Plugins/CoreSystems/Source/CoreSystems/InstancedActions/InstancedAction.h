// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InstancedAction.generated.h"

/**
 * 
 */
UCLASS(DefaultToInstanced, Blueprintable)
class CORESYSTEMS_API UInstancedAction : public UObject
{
	GENERATED_BODY()

public:
	virtual void Execute(){}
};
