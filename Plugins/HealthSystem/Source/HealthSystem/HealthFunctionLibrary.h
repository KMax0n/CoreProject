// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HealthFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class HEALTHSYSTEM_API UHealthFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static void ApplyDamage(AActor* Victim);
};
