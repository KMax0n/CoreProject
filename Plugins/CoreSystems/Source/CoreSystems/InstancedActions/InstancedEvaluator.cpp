// Fill out your copyright notice in the Description page of Project Settings.

#include "InstancedEvaluator.h"

UInstancedEvaluator::UInstancedEvaluator()
{
	bEnable = true;
}

float UInstancedEvaluator::Evaluate(AActor* ContextActor)
{
	Context = ContextActor;
	const float Score = K2_Evaluate();
	//UE_LOG(LogInstancedActions, Log, TEXT("%s score = %f"), *this->GetName(), Score);
	return Score;
}
