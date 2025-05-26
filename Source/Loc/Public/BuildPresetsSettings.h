#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "BuildPresetsSettings.generated.h"

class UBuildToolPresetExecutionStrategy;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOC_API UBuildPresetsSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UBuildToolPresetExecutionStrategy> ConstructableConfigStrategy;
    
    UBuildPresetsSettings();

};

