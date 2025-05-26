#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "VillageSubsystem_EventDelegate.h"
#include "VillageLoadSimulationSubsystem.generated.h"

class UBiomeTrackerSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UVillageLoadSimulationSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVillageSubsystem_Event OnVillageLoadingEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVillageSubsystem_Event OnVillageLoadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVillageSubsystem_Event OnVillageUnloadedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBiomeTrackerSimulationComponent*> BiomeTrackerComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentPlayersInVillage;
    
    UVillageLoadSimulationSubsystem();

};

