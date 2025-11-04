
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "InstancedActionsData.generated.h"

DECLARE_LOG_CATEGORY_CLASS(LogInstancedActions, Log, All);

UENUM(BlueprintType)
namespace EEnumEvaluationMode
{
	enum Type : int
	{
		Multiply,
		Add,
		Override,
	};
}