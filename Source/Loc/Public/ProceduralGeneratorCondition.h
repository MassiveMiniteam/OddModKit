#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProceduralGeneratorCondition.generated.h"

class UBiomeCellInstance;
class UBiomeInstance;
class UWorldGenerator;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition : public UObject {
    GENERATED_BODY()
public:
    UProceduralGeneratorCondition();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsAllowed(UWorldGenerator* WorldGenerator, int32 InSeed, UBiomeCellInstance* TargetCell, UBiomeInstance* TargetBiome);
    
};

