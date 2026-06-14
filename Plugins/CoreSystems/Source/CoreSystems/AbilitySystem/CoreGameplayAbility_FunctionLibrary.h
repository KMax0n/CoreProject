// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Abilities/GameplayAbilityTargetTypes.h"

#include "CoreGameplayAbility_FunctionLibrary.generated.h"

struct FGameplayAbilityTargetData;

USTRUCT(Blueprintable)
struct FAbilityMontageData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAnimMontage> Montage;
};

USTRUCT(Blueprintable)
struct FGameplayAbilityTargetData_MontageData : public FGameplayAbilityTargetData
{
	GENERATED_BODY()

	FAbilityMontageData MontageData;

	virtual UScriptStruct* GetScriptStruct() const override
	{
		return FGameplayAbilityTargetData_MontageData::StaticStruct();
	}
};

UCLASS()
class CORESYSTEMS_API UCoreGameplayAbility_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure)
	static FGameplayAbilityTargetDataHandle MakeTargetDataFromMontageData(const FAbilityMontageData& MontageData);

	UFUNCTION(BlueprintPure)
	static FAbilityMontageData GetMontageDataFromTargetData(const FGameplayAbilityTargetDataHandle& Data);
};
