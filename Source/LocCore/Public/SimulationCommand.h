#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocPlayerId.h"
#include "SimulationCommand.generated.h"

class ASimulationManager;
class UWorld;

UCLASS(Blueprintable)
class LOCCORE_API USimulationCommand : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> TemporaryWorld;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FLocPlayerId OwnerId;
    
    USimulationCommand();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString ToString();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void Schedule(const UObject* WorldContext, bool bScheduleAsPrediction);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRunCommand(ASimulationManager* SimulationManager, bool bRunAsPrediction);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetSupportsPrediction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetSupportsLoadingFromSavegame();
    
};

