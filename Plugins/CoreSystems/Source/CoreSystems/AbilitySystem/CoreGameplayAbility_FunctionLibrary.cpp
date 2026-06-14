// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameplayAbility_FunctionLibrary.h"


FGameplayAbilityTargetDataHandle UCoreGameplayAbility_FunctionLibrary::MakeTargetDataFromMontageData(const FAbilityMontageData& MontageData)
{
	FGameplayAbilityTargetData_MontageData* Data = new FGameplayAbilityTargetData_MontageData();
	Data->MontageData = MontageData;
	
	FGameplayAbilityTargetDataHandle TargetData;
	TargetData.Add(Data);
	
	return TargetData;
}

FAbilityMontageData UCoreGameplayAbility_FunctionLibrary::GetMontageDataFromTargetData(const FGameplayAbilityTargetDataHandle& Handle)
{
	if (const FGameplayAbilityTargetData* Data = Handle.Get(0))
	{
		if (Data->GetScriptStruct() == FGameplayAbilityTargetData_MontageData::StaticStruct())
		{
			const FGameplayAbilityTargetData_MontageData* NameData = static_cast<const FGameplayAbilityTargetData_MontageData*>(Data);
			return NameData->MontageData;
		}
	}
	
	return FAbilityMontageData();
}
