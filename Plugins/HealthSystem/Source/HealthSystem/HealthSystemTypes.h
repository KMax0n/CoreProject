#pragma once

#include "GameplayTagContainer.h"
#include "HealthSystemTypes.generated.h"

USTRUCT(Blueprintable)
struct FDamageInfo
{
	GENERATED_BODY()
	
	FGameplayTag DamageTypeTag;
	float Damage;
	TSoftObjectPtr<AActor> Taget;
	TSoftObjectPtr<AActor> Instigator;
	FVector HitLocation;
	FVector HitNormal;
};

UCLASS(Blueprintable)
class UBaseDamageType : public UDamageType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FDamageInfo DamageInfo;
};
