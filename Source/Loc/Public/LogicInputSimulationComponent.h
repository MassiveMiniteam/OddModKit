#pragma once
#include "CoreMinimal.h"
#include "LogicConnectionSimulationComponent.h"
#include "LogicInputSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicInputSimulationComponent : public ULogicConnectionSimulationComponent {
    GENERATED_BODY()
public:
    ULogicInputSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAsInt(FName Channel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAsBool(FName Channel) const;
    
};

