// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_MeleeHit.h"

#include "KismetTraceUtils.h"

UAnimNotifyState_MeleeHit::UAnimNotifyState_MeleeHit()
{
	NotifyColor = FColor::Red;

	
}

void UAnimNotifyState_MeleeHit::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	//EventReference.AddContextData<FAnimNotifyMeleeEvent>(true);

	//auto NotifyEvent = EventReference.GetContextData<FAnimNotifyMeleeEvent>();
	LastTraceLocation = MeshComp->GetSocketLocation(SocketLocaiton);

	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
}

void UAnimNotifyState_MeleeHit::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{ 
	const auto CurrentTraceLocation = MeshComp->GetSocketLocation(SocketLocaiton);

	FHitResult HitResult = FHitResult();
	DrawDebugSphereTraceSingle(MeshComp->GetWorld(), LastTraceLocation, CurrentTraceLocation, 15.0f, EDrawDebugTrace::ForDuration, true, HitResult, FLinearColor::Green, FLinearColor::Red, 1.0f);

	if (HitResult.bBlockingHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hit"));
	}

	LastTraceLocation = CurrentTraceLocation;
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);
}


