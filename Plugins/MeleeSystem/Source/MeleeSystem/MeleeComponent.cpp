// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeComponent.h"

#include "InstancedActions/Evaluators/InstancedEvaluator_MeleeTarget.h"


// Sets default values for this component's properties
UMeleeComponent::UMeleeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMeleeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMeleeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMeleeComponent::SetCurrentAction(EActionType NewAction, EZone NewZone)
{
	CurrentAction = NewAction;
	CurrentZone = NewZone;
}

void UMeleeComponent::SetCurrentZone(EZone NewZone)
{
	CurrentZone = NewZone;
}

void UMeleeComponent::SetCurrentTarget(AActor* NewTarget)
{
	CurrentTarget = NewTarget;
}

void UMeleeComponent::UpdateCurrentTarget()
{
	AActor* BestCandidate = nullptr;
	float BestScore = -1.f;
	
	for (const auto CurCandidate : TargetCandidates)
	{
		float CurScore = 0.f;
		
		for (auto* Evaluator : TargetEvaluators)
		{
			if (Evaluator && Evaluator->bEnable)
			{
				float Score = Evaluator->Evaluate(GetOwner(), CurCandidate);

				switch (Evaluator->EvaluationMode)
				{
					case EEnumEvaluationMode::Multiply:
						CurScore *= Score;
						break;
					case EEnumEvaluationMode::Add:
						CurScore += Score;
						break;
					case EEnumEvaluationMode::Override:
						CurScore = Score;
						break;
					default:
						break;
				}
			}
		}

		if (CurScore > BestScore)
		{
			BestScore = CurScore;
			BestCandidate = CurCandidate;
		}
	}

	CurrentTarget = BestCandidate;
}
