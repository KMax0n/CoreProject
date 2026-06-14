// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

namespace HitReactionDebug
{
	static TAutoConsoleVariable<bool> CVarDebugHitReactionSystem
	(
	TEXT("Debug.HitReactions"),
	false,
	TEXT("When true, show debug traces and hit points")
	);
}

class FHitReactionSystemModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
