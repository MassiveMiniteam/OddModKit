#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocRandom.h"
#include "ProceduralCellGenerator.generated.h"

class UBiomeCellInstance;
class UBiomeInstance;
class UWorldGenerator;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class LOC_API UProceduralCellGenerator : public UObject {
    GENERATED_BODY()
public:
    UProceduralCellGenerator();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NativeGenerate(FLocRandom& Random, UWorldGenerator* WorldGenerator, UBiomeInstance* BiomeInstance, TArray<UBiomeInstance*>& BiomeInstances, TArray<UBiomeCellInstance*>& CellInstances);
    
public:
    UFUNCTION(BlueprintCallable)
    FString GetDescription();
    
    UFUNCTION(BlueprintCallable)
    void Generate(FLocRandom& Random, UWorldGenerator* WorldGenerator, UBiomeInstance* BiomeInstance, TArray<UBiomeInstance*>& BiomeInstances, TArray<UBiomeCellInstance*>& CellInstances);
    
};

