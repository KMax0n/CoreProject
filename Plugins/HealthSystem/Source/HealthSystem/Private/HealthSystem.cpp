#include "HealthSystem.h"

#include "GameplayDebugger.h"
#include "HealthSystem/GameplayDebugger/GameplayDebuggerCategory_Health.h"

#define LOCTEXT_NAMESPACE "FHealthSystemModule"

void FHealthSystemModule::StartupModule()
{
#if WITH_GAMEPLAY_DEBUGGER
	IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
	GameplayDebuggerModule.RegisterCategory("Health", IGameplayDebugger::FOnGetCategory::CreateStatic(&FGameplayDebuggerCategory_Health::MakeInstance), EGameplayDebuggerCategoryState::EnabledInGameAndSimulate, 7);
	GameplayDebuggerModule.NotifyCategoriesChanged();
#endif // WITH_GAMEPLAY_DEBUGGER
}

void FHealthSystemModule::ShutdownModule()
{
#if WITH_GAMEPLAY_DEBUGGER
	if (IGameplayDebugger::IsAvailable())
	{
		IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
		GameplayDebuggerModule.UnregisterCategory("Health");
		GameplayDebuggerModule.NotifyCategoriesChanged();
	}
#endif // WITH_GAMEPLAY_DEBUGGER
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FHealthSystemModule, HealthSystem)