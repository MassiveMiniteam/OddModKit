#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SteamDeckUtils.generated.h"

class UWidget;

UCLASS(Blueprintable)
class MMTSTEAMDECK_API USteamDeckUtils : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USteamDeckUtils();

    UFUNCTION(BlueprintCallable)
    static bool ShowSteamDeckKeyboard(UWidget* Widget);
    
};

