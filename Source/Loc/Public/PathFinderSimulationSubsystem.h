#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocSimulationSubsystem.h"
#include "PathFindingSettings.h"
#include "PathFinderSimulationSubsystem.generated.h"

class UPathFindingRequest;

UCLASS(Blueprintable)
class LOC_API UPathFinderSimulationSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UPathFindingRequest*> Requests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ClosedSetLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ForceCompleteClosedSetLimit;
    
public:
    UPathFinderSimulationSubsystem();

    UFUNCTION(BlueprintCallable)
    UPathFindingRequest* FindPath(const FPathFindingSettings& Settings, FIntVector FromPosition, FIntVector ToPosition);
    
};

