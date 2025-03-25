// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTask_PlayMontageAndWaitNotify.h"

#include <AbilitySystemGlobals.h>
#include <Animation/AnimMontage.h>

UAbilityTask_PlayMontageAndWaitNotify* UAbilityTask_PlayMontageAndWaitNotify::PlayMontageAndWaitNotifyProxy(UGameplayAbility* OwningAbility,
    FName TaskInstanceName, UAnimMontage* MontageToPlay, float Rate, FName StartSection, bool bStopWhenAbilityEnds, float AnimRootMotionTranslationScale, float StartTimeSeconds, bool bAllowInterruptAfterBlendOut)
{
    UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(Rate);

    UAbilityTask_PlayMontageAndWaitNotify* MyObj = NewAbilityTask<UAbilityTask_PlayMontageAndWaitNotify>(OwningAbility, TaskInstanceName);
    MyObj->MontageToPlay = MontageToPlay;
    MyObj->Rate = Rate;
    MyObj->StartSection = StartSection;
    MyObj->AnimRootMotionTranslationScale = AnimRootMotionTranslationScale;
    MyObj->bStopWhenAbilityEnds = bStopWhenAbilityEnds;
    MyObj->bAllowInterruptAfterBlendOut = bAllowInterruptAfterBlendOut;
    MyObj->StartTimeSeconds = StartTimeSeconds;

    return MyObj;
}

void UAbilityTask_PlayMontageAndWaitNotify::Activate()
{
    if (Ability == nullptr)
    {
        return;
    }

    if (UAbilitySystemComponent* ASC = AbilitySystemComponent.Get())
    {
        const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
        UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();
        if (AnimInstance != nullptr)
        {
            AnimInstance->OnPlayMontageNotifyBegin.AddDynamic(this, &ThisClass::OnNotifyBeginReceived);
            AnimInstance->OnPlayMontageNotifyEnd.AddDynamic(this, &ThisClass::OnNotifyEndReceived);

            //Use logic from parent
            Super::Activate();
        }

        if (FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(MontageToPlay))
        {
            MontageInstanceID = MontageInstance->GetInstanceID();
        }
    }
}

void UAbilityTask_PlayMontageAndWaitNotify::OnDestroy(bool AbilityEnded)
{
    if (UAbilitySystemComponent* ASC = AbilitySystemComponent.Get())
    {
        const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
        UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();

        if (AnimInstance != nullptr)
        {
            AnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic(this, &ThisClass::OnNotifyBeginReceived);
            AnimInstance->OnPlayMontageNotifyEnd.RemoveDynamic(this, &ThisClass::OnNotifyEndReceived);
        }
    }

    Super::OnDestroy(AbilityEnded);

}

bool UAbilityTask_PlayMontageAndWaitNotify::IsNotifyValid(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload) const
{
    return ((MontageInstanceID != INDEX_NONE) && (BranchingPointNotifyPayload.MontageInstanceID == MontageInstanceID));
}


void UAbilityTask_PlayMontageAndWaitNotify::OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{
    if (IsNotifyValid(NotifyName, BranchingPointNotifyPayload))
    {
        OnNotifyBegin.Broadcast(NotifyName);
    }
}

void UAbilityTask_PlayMontageAndWaitNotify::OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{
    if (IsNotifyValid(NotifyName, BranchingPointNotifyPayload))
    {
        OnNotifyEnd.Broadcast(NotifyName);
    }
}