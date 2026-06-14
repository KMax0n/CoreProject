#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

namespace MeleeSystemConsoleVar
{
    static TAutoConsoleVariable<bool> CVarDebugMeleeSystemAttack
    (
    TEXT("Debug.Melee.Attack"),
    false,
    TEXT("When true, show debug traces and hit points")
    );
}

class FMeleeSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
