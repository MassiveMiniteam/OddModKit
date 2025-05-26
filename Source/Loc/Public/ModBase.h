#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SimulationActorHookArray.h"
#include "WidgetHookArray.h"
#include "ModReplacedObject.h"
#include "ModBase.generated.h"

class AModSimulationActor;
class UModInstance;
class UModSettings;
class UModSettingsWidget;

UCLASS(Blueprintable)
class LOC_API UModBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> OverrideObjectPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FModReplacedObject> ModdedRuntimeObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AModSimulationActor>> ModSimulationActorClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UModSettings> ModSettingsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UModSettingsWidget> ModSettingsWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UClass*, FSimulationActorHookArray> SimulationActorHooks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UClass*, FWidgetHookArray> WidgetHooks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> ModdedLanguages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModSettings* ModSettings;
    
    UModBase();

    UFUNCTION(BlueprintCallable)
    void RegisterObjectForOverride(UObject* Object);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModEnabled(UModInstance* ModInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnModDisabled(UModInstance* ModInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsCompatibleWithVersion(const FString& Version);
    
};

