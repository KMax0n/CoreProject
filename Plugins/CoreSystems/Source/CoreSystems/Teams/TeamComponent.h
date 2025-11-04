// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GenericTeamAgentInterface.h"

#include "TeamComponent.generated.h"


UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CORESYSTEMS_API UTeamComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTeamComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintSetter, Category = "Teams")
	void SetTeamId(const uint8 NewTeamId); 

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintGetter, Category = "Teams")
	uint8 GetTeamId() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Teams")
	uint8 TeamId;

private:
	IGenericTeamAgentInterface* OwnerTeamAgentInterface;
};
