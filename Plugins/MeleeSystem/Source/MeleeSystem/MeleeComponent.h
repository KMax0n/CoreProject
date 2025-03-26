// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ActionData.h"

#include "MeleeComponent.generated.h"


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
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetCurrentAction(EActionType NewAction, EZone NewZone = EZone::Middle);

	UFUNCTION(BlueprintCallable)
	void SetCurrentZone(EZone NewZone = EZone::Middle);
	
	UPROPERTY(BlueprintReadOnly)
	EActionType CurrentAction;

	UPROPERTY(BlueprintReadOnly)
	EZone CurrentZone;
};
