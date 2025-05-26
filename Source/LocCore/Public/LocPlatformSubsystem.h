#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EPS5ActivityOutcome.h"
#include "LocPlatformSubsystem.generated.h"

class APlayerController;

UCLASS(Blueprintable)
class LOCCORE_API ULocPlatformSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    ULocPlatformSubsystem();

    UFUNCTION(BlueprintCallable)
    void StartActivity(const FString& ActivityId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetPresence(const FString& Key) const;
    
    UFUNCTION(BlueprintCallable)
    static void OpenLunaVirtualKeyboard();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetNickName(APlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable)
    FString GetLunaPlayerName();
    
    UFUNCTION(BlueprintCallable)
    FString GetLunaPlayerId();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetLunaLanguage();
    
    UFUNCTION(BlueprintCallable)
    void EndActivity(const FString& ActivityId, EPS5ActivityOutcome ActivityOutcome);
    
};

