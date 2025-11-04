// Fill out your copyright notice in the Description page of Project Settings.


#include "InstancedEvaluator_MeleeTarget.h"

float UInstancedEvaluator_MeleeTarget::Evaluate(AActor* ContextActor, AActor* TargetActor)
{
	TargetCandidate = TargetActor;

	return Super::Evaluate(ContextActor);
}
