#pragma once
#include "CoreMinimal.h"
#include "EQuestState.generated.h"

UENUM(BlueprintType)
enum EQuestState {
    Unknown,
    Available,
    Accepted,
    Completed,
};

