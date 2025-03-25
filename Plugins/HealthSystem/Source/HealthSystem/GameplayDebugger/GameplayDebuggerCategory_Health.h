// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"

class FGameplayDebuggerCategory_Health : public FGameplayDebuggerCategory
{
public:
	// Sets default values for this actor's properties
	FGameplayDebuggerCategory_Health(){}

	virtual void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
	virtual void OnDataPackReplicated(int32 DataPackId) override;
	virtual void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;
	virtual FDebugRenderSceneProxy* CreateDebugSceneProxy(const UPrimitiveComponent* InComponent, FDebugDrawDelegateHelper*& OutDelegateHelper) override;

	HEALTHSYSTEM_API static TSharedRef<FGameplayDebuggerCategory> MakeInstance();
protected:

public:
};
#endif
