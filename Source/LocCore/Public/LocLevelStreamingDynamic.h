#pragma once
#include "CoreMinimal.h"
#include "Engine/LevelStreaming.h"
#include "LocLevelStreamingDynamic.generated.h"

class UObject;
class UWorld;

UCLASS(Blueprintable, EditInlineNew)
class LOCCORE_API ULocLevelStreamingDynamic : public ULevelStreaming {
    GENERATED_BODY()
public:
    ULocLevelStreamingDynamic();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LocUnLoadStreamingLevelWithNoReplication(const UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LocUnLoadAllStreamingLevelsWithNoReplication(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LocLoadStreamingLevelWithNoReplication(const UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level);
    
};

