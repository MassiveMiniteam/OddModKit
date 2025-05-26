#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SeasonalEventsSettings.generated.h"

class UBiomeCellConfig;
class USeasonalEventData;
class USeasonalEventsSettings;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOC_API USeasonalEventsSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<USeasonalEventData>> SeasonalEventDataAssets;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UBiomeCellConfig> VillageBiome;
    
    USeasonalEventsSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static USeasonalEventsSettings* GetSeasonalDeveloperSettings();
    
};

