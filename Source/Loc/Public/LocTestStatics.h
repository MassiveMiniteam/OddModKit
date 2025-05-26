#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LocTestStatics.generated.h"

class UBiomeCellConfig;
class UObject;

UCLASS(Blueprintable)
class LOC_API ULocTestStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULocTestStatics();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static TArray<int32> TestForInvalidSeeds(const UObject* WorldContext, int32 Amount, TMap<UBiomeCellConfig*, int32> VerifySpawned);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static TArray<FString> GetCyclicAssetRedirectors(const UObject* WorldContext);
    
};

