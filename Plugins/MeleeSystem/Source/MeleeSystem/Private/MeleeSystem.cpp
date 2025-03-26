#include "../Public/MeleeSystem.h"

#include "GameplayDebugger.h"
#include "..\GameplayDebugger\GameplayDebuggerCategory_Melee.h"

#define LOCTEXT_NAMESPACE "FHealthSystemModule"

void FMeleeSystemModule::StartupModule()
{
#if WITH_GAMEPLAY_DEBUGGER
	IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
	GameplayDebuggerModule.RegisterCategory("Melee", IGameplayDebugger::FOnGetCategory::CreateStatic(FGameplayDebuggerCategory_Melee::MakeInstance), EGameplayDebuggerCategoryState::EnabledInGameAndSimulate, 7);
	GameplayDebuggerModule.NotifyCategoriesChanged();
#endif // WITH_GAMEPLAY_DEBUGGER
}

void FMeleeSystemModule::ShutdownModule()
{
#if WITH_GAMEPLAY_DEBUGGER
	if (IGameplayDebugger::IsAvailable())
	{
		IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
		GameplayDebuggerModule.UnregisterCategory("Melee");
		GameplayDebuggerModule.NotifyCategoriesChanged();
	}
#endif // WITH_GAMEPLAY_DEBUGGER
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FMeleeSystemModule, MeleeSystem)