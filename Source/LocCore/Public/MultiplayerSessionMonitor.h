#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MultiplayerSessionMonitor.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API UMultiplayerSessionMonitor : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UMultiplayerSessionMonitor();

};

