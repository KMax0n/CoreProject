// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayDebuggerCategory_Health.h"

void FGameplayDebuggerCategory_Health::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	FGameplayDebuggerCategory::CollectData(OwnerPC, DebugActor);
}

void FGameplayDebuggerCategory_Health::OnDataPackReplicated(int32 DataPackId)
{
	FGameplayDebuggerCategory::OnDataPackReplicated(DataPackId);
}

void FGameplayDebuggerCategory_Health::DrawData(APlayerController* OwnerPC,
	FGameplayDebuggerCanvasContext& CanvasContext)
{
	FGameplayDebuggerCategory::DrawData(OwnerPC, CanvasContext);
}

FDebugRenderSceneProxy* FGameplayDebuggerCategory_Health::CreateDebugSceneProxy(const UPrimitiveComponent* InComponent,
	FDebugDrawDelegateHelper*& OutDelegateHelper)
{
	return FGameplayDebuggerCategory::CreateDebugSceneProxy(InComponent, OutDelegateHelper);
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_Health::MakeInstance()
{
	return MakeShareable(new FGameplayDebuggerCategory_Health());
}
