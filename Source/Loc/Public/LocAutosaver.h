#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocAutosaver.generated.h"

class ULocSaveGame;

UCLASS(Blueprintable)
class LOC_API ALocAutosaver : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeUntilAutosave;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BeforeAutoSaveDelay;
    
public:
    ALocAutosaver(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TriggerAutosaveForSaveGame(ULocSaveGame* SaveGame);
    
    UFUNCTION(BlueprintCallable)
    void SimulateAutosave();
    
    UFUNCTION(BlueprintCallable)
    void ResetAutosaveTimer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeforeAutoSave();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAutosaved();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeUntilAutosave() const;
    
};

