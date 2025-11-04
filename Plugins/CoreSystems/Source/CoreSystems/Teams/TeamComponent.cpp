// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamComponent.h"



// Sets default values for this component's properties
UTeamComponent::UTeamComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTeamComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerTeamAgentInterface = Cast<IGenericTeamAgentInterface>(GetOwner());

	if (OwnerTeamAgentInterface)
	{
		OwnerTeamAgentInterface->SetGenericTeamId(TeamId);
	}
}

void UTeamComponent::SetTeamId(const uint8 NewTeamId)
{
	TeamId = NewTeamId;
	
	if (OwnerTeamAgentInterface)
	{
		OwnerTeamAgentInterface->SetGenericTeamId(TeamId);
	}
}

// Called every frame
void UTeamComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

uint8 UTeamComponent::GetTeamId() const
{
	return OwnerTeamAgentInterface ? OwnerTeamAgentInterface->GetGenericTeamId().GetId() : TeamId;
}