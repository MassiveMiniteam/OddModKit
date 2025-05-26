#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "CopyToolPropertyValueWrapper.h"
#include "CopyToolUseable.h"
#include "CopyToolUsableSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCopyToolUsableSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UCopyToolUsableSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPasteValues(UPARAM(Ref) FCopyToolPropertyValueWrapper& PropertyValueWrapper);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<FCopyToolPropertyValueWrapper> OnCopyValues();
    

    // Fix for true pure virtual functions not being implemented
};

