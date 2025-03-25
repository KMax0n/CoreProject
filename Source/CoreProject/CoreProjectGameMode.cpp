// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreProjectGameMode.h"
#include "CoreProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACoreProjectGameMode::ACoreProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
