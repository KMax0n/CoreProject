// Fill out your copyright notice in the Description page of Project Settings.

#include "InstancedEvaluator.h"

UInstancedEvaluator::UInstancedEvaluator()
{
	bEnable = true;
}

float UInstancedEvaluator::Evaluate(AActor* ContextActor)
{
	const float Score = K2_Evaluate();
	UE_LOG(LogInstancedActions, Log, TEXT("UInstancedEvaluator::Evaluation score = %f"), Score);
	return Score;
}
