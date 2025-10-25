// Fill out your copyright notice in the Description page of Project Settings.


#include "Core_MotionWarpingComponent.h"

void UCore_MotionWarpingComponent::CallOnUpdateTarget(const FName& WarpTargetName)
{
	OnUpdateTarget.Broadcast(WarpTargetName);
}
