#pragma once

#include "CoreMinimal.h"
#include "ActionData.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	None,
	Attack,
	Defend,
	Dash,
};

UENUM(BlueprintType)
enum class EZone : uint8
{
	None,
	Middle,
	Top,
	Horizontal,
	Any
};

/*
USTRUCT(BlueprintType)
struct FActionData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	EActionType Action;
};

USTRUCT(BlueprintType)
struct MELEESYSTEM_API FAttackActionData : public FActionData 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	EZone AttackZone;
};

USTRUCT(BlueprintType)
struct MELEESYSTEM_API FDefendActionData : public FActionData 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	EZone DefendZone;
};
*/
