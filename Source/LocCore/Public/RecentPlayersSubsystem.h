#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "RecentPlayersSubsystem.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API URecentPlayersSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    URecentPlayersSubsystem();

};

