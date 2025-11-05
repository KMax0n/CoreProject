// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ActionData.h"

#include "MeleeComponent.generated.h"

class UInstancedEvaluator_MeleeTarget;
class UInstancedEvaluator;


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class MELEESYSTEM_API UMeleeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMeleeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetCurrentAction(EActionType NewAction, EZone NewZone = EZone::Middle);

	UFUNCTION(BlueprintCallable)
	void SetCurrentZone(EZone NewZone = EZone::Middle);

	//MeleeTarget
protected:
	UFUNCTION(BlueprintCallable, Category = "Target")
	AActor* GetCurrentTarget() const {return CurrentTarget;}

	UFUNCTION(BlueprintCallable, Category = "Target")
	void SetCurrentTarget(AActor* NewTarget);

	UFUNCTION(BlueprintCallable, Category = "Target")
	void UpdateCurrentTarget();
	
	UPROPERTY();
	AActor* CurrentTarget;

	UPROPERTY(BlueprintReadWrite)
	TArray<AActor*> TargetCandidates;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Target")
	TArray<UInstancedEvaluator_MeleeTarget*> TargetEvaluators;

public:
	UPROPERTY(BlueprintReadOnly)
	EActionType CurrentAction;

	UPROPERTY(BlueprintReadOnly)
	EZone CurrentZone;

};
