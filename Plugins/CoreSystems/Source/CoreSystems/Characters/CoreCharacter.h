// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CoreSystems/MotionWarping/Core_MotionWarpingComponent.h"
#include "GenericTeamAgentInterface.h"

#include "CoreCharacter.generated.h"

UCLASS(Blueprintable, BlueprintType)
class CORESYSTEMS_API ACoreCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACoreCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Teams
	UFUNCTION(BlueprintCallable, Category = "Characters")
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;

	UFUNCTION(BlueprintCallable, Category = "Characters")
	virtual FGenericTeamId GetGenericTeamId() const override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UCore_MotionWarpingComponent* MotionWarpingComponent;
};
