#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LocAIStatics.generated.h"

class ASimulationActor;
class UBlackboardComponent;
class UObject;

UCLASS(Blueprintable)
class LOC_API ULocAIStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULocAIStatics();

    UFUNCTION(BlueprintCallable)
    static void SetValueAsIntVector(UBlackboardComponent* Blackboard, const FName& KeyName, FIntVector VectorValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FIntVector GetValueAsIntVector(UBlackboardComponent* Blackboard, const FName& KeyName);
    
    UFUNCTION(BlueprintCallable)
    static bool GetTargetByClustering(const TArray<ASimulationActor*>& Actors, FIntVector& OutTargetPosition, int32 Range);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static bool GetIsDiggableBetweenSparkAndTargetPosition(const UObject* WorldContext, const FIntVector& Target, const FIntVector& From);
    
};

