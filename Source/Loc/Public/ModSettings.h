#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "ModSettings.generated.h"

UCLASS(Blueprintable)
class LOC_API UModSettings : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UModSettings();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSettingsWantToSave();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSettingsLoaded(const FString& Version);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSettingsCreated();
    
};

