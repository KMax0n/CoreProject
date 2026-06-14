// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "HealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta=(HideInDetailsView))
class HEALTHSYSTEM_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthAttribute", meta = (HideFromModifiers))
	float	MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthAttribute", meta = (HideFromModifiers))
	float	Health;
};
