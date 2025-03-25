// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCheatManager.h"

#include "Engine/DebugCameraController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogCheatManager);

AActor* UBaseCheatManagerExtension::GetSelectedActor() const
{
	if (auto* Manager = Cast<UBaseCheatManager>(GetOuterUCheatManager()))
	{
		if (Manager->GetSelectedActor())
			return Manager->GetSelectedActor();
	}

	const AActor* PlayerActor = GetPlayerController()->GetPawn();
	const FVector PlayerLocation = PlayerActor->K2_GetActorLocation();

	UE_LOG(LogCheatManager, Verbose, TEXT("PlayerLocation = %s"), *PlayerLocation.ToString())

	AActor* ClosestActor = nullptr;
	float MinDistance = 999999.0f;
	TArray<AActor*> ActorsToDebug;
	UGameplayStatics::GetAllActorsOfClass(GetPlayerController(), ACharacter::StaticClass(), ActorsToDebug);

 	for (auto* Actor : ActorsToDebug)
	{
		if (PlayerActor != Actor)
		{
			const float CurDistance = FVector::Dist(PlayerLocation, Actor->GetActorLocation());

			if (CurDistance < MinDistance)
            	{
            		MinDistance = CurDistance;
            		ClosestActor = Actor;
            	}
		}
		
	}
	
	UE_LOG(LogCheatManager, Verbose, TEXT("ClosestActor = %s"), *ClosestActor->GetName())
	UE_LOG(LogCheatManager, Verbose, TEXT("ClosestDistance = %f"), MinDistance)
	
	return ClosestActor;
}

void UBaseCheatManager::InitCheatManager()
{
	Super::InitCheatManager();

	for (const auto ExtensionClass : CheatExtensionsClasses)
	{
		if (ExtensionClass)
		{
			const UClass* Class = ExtensionClass.Get();

			if (auto* NewExtension = NewObject<UBaseCheatManagerExtension>(this, Class, *Class->GetName()))
			{
				AddCheatManagerExtension(NewExtension);
			}
		}
	}
}

AActor* UBaseCheatManager::GetSelectedActor()
{
	return DebugCameraControllerRef ? DebugCameraControllerRef->GetSelectedActor() : nullptr;
}
