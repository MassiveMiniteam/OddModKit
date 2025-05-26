#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocSimulationSubsystem.h"
#include "PositionPushbackBitmaskSetting.h"
#include "PositionPushbackSimulationSubsystem.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOC_API UPositionPushbackSimulationSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPositionPushbackBitmaskSetting> BitmaskSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 PushDirectorCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> PushDirections;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPositionSimulationComponent*> PositionComponents;
    
public:
    UPositionPushbackSimulationSubsystem();

};

