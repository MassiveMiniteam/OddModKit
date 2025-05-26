#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlatformMultiplayerLibrary.generated.h"

class APlayerState;
class UObject;

UCLASS(Blueprintable)
class LOCCORE_API UPlatformMultiplayerLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPlatformMultiplayerLibrary();

    UFUNCTION(BlueprintCallable)
    static void ShowPlayerProfileUI(UObject* ContextObject, APlayerState* TargetPlayerState, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void KickPlayer(UObject* WorldContext, APlayerState* PlayerState, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void InvitePlayer(bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void BanPlayer(UObject* WorldContext, APlayerState* PlayerNetId, bool& bSuccess);
    
};

