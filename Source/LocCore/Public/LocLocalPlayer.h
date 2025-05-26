#pragma once
#include "CoreMinimal.h"
#include "Engine/LocalPlayer.h"
#include "LocLocalPlayer.generated.h"

UCLASS(Blueprintable, NonTransient)
class LOCCORE_API ULocLocalPlayer : public ULocalPlayer {
    GENERATED_BODY()
public:
    ULocLocalPlayer();

};

