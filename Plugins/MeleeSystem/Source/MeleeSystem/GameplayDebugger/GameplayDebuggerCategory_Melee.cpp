// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayDebuggerCategory_Melee.h"

void FGameplayDebuggerCategory_Melee::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	FGameplayDebuggerCategory::CollectData(OwnerPC, DebugActor);
}

void FGameplayDebuggerCategory_Melee::OnDataPackReplicated(int32 DataPackId)
{
	FGameplayDebuggerCategory::OnDataPackReplicated(DataPackId);
}

void FGameplayDebuggerCategory_Melee::DrawData(APlayerController* OwnerPC,
	FGameplayDebuggerCanvasContext& CanvasContext)
{
	FGameplayDebuggerCategory::DrawData(OwnerPC, CanvasContext);
}

FDebugRenderSceneProxy* FGameplayDebuggerCategory_Melee::CreateDebugSceneProxy(const UPrimitiveComponent* InComponent,
	FDebugDrawDelegateHelper*& OutDelegateHelper)
{
	return FGameplayDebuggerCategory::CreateDebugSceneProxy(InComponent, OutDelegateHelper);
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_Melee::MakeInstance()
{
	return MakeShareable(new FGameplayDebuggerCategory_Melee());
}
