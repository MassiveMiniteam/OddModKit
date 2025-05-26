#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProceduralWorldGenerator.generated.h"

class UBiomeCellInstance;
class UBiomeInstance;
class UWorldGenerator;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class LOC_API UProceduralWorldGenerator : public UObject {
    GENERATED_BODY()
public:
    UProceduralWorldGenerator();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NativeGenerate(UWorldGenerator* WorldGenerator, int32 InSeed, TArray<UBiomeInstance*>& BiomeInstances, TArray<UBiomeCellInstance*>& CellInstances);
    
public:
    UFUNCTION(BlueprintCallable)
    FString GetDescription();
    
    UFUNCTION(BlueprintCallable)
    void Generate(UWorldGenerator* WorldGenerator, int32 InSeed, TArray<UBiomeInstance*>& BiomeInstances, TArray<UBiomeCellInstance*>& CellInstances);
    
};

