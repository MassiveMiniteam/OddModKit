#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DesyncDebuggerSubsystem.generated.h"

class ASimulationManager;

UCLASS(Blueprintable)
class LOC_API UDesyncDebuggerSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSaveGameDumping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SkipDumpFrames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DumpSkipCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SaveGameDumpPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> FilesToVerify;
    
public:
    UDesyncDebuggerSubsystem();

private:
    UFUNCTION(BlueprintCallable)
    void OnSimulationTick(ASimulationManager* SimulationManager);
    
};

