// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"

#include "BaseCheatManager.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCheatManager, Log, All);

UCLASS()
class DEBUGSYSTEM_API UBaseCheatManagerExtension : public UCheatManagerExtension
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category = "Debug")
	AActor* GetSelectedActor() const;
	
public:
	UFUNCTION(BlueprintImplementableEvent, DisplayName = "GetActorForDebug", Category = "Debug")
	AActor* K2_GetActorForDebug();
};

UCLASS()
class DEBUGSYSTEM_API UBaseCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	virtual void InitCheatManager() override;

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "GetActorForDebug", Category = "Debug")
	AActor* K2_GetActorForDebug();
	
	UFUNCTION(BlueprintPure, Category = "Debug")
	virtual AActor* GetSelectedActor();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Debug")
	TArray<TSubclassOf<UBaseCheatManagerExtension>> CheatExtensionsClasses;
private:
	TWeakObjectPtr<AActor> SelectedActor;
};
