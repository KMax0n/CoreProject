// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotionWarpingComponent.h"

#include "Core_MotionWarpingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateTargetSignature, const FName&, WarpTargetName);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CORESYSTEMS_API UCore_MotionWarpingComponent : public UMotionWarpingComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MotionWarping")
	void CallOnUpdateTarget(const FName& WarpTargetName);

	UPROPERTY(BlueprintAssignable, Category = "MotionWarping")
	FOnUpdateTargetSignature OnUpdateTarget;

};
