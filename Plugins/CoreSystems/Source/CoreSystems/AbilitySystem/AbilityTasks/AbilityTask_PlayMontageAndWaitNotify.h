// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

#include "AbilityTask_PlayMontageAndWaitNotify.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayMontageNotifyDelegate, FName, NotifyName);

class UAnimMontage;

UCLASS()
class CORESYSTEMS_API UAbilityTask_PlayMontageAndWaitNotify : public UAbilityTask_PlayMontageAndWait
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName="PlayMontageAndWaitNotify", /*HidePin = "OwningAbility", */DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_PlayMontageAndWaitNotify* PlayMontageAndWaitNotifyProxy(UGameplayAbility* OwningAbility,
		FName InTaskInstanceName, UAnimMontage* InMontageToPlay, float InRate = 1.f, FName InStartSection = NAME_None,
		bool InStopWhenAbilityEnds = true, float InAnimRootMotionTranslationScale = 1.f, float InStartTimeSeconds = 0.f,
		bool InAllowInterruptAfterBlendOut = false);

	virtual void Activate() override;

protected:
	virtual void OnDestroy(bool AbilityEnded) override;

	UFUNCTION()
	void OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UFUNCTION()
	void OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	bool IsNotifyValid(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload) const;

	int32 MontageInstanceID = -1;
	

public:
	UPROPERTY(BlueprintAssignable)
	FOnPlayMontageNotifyDelegate OnNotifyBegin;

	UPROPERTY(BlueprintAssignable)
	FOnPlayMontageNotifyDelegate OnNotifyEnd;
};