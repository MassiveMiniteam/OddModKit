#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "PaintReceiverPresentationStrategy.generated.h"

class UColorItemConfig;
class UPaintReceiverPresentationComponent;
class UPaintReceiverSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UPaintReceiverPresentationStrategy : public UObject {
    GENERATED_BODY()
public:
    UPaintReceiverPresentationStrategy();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnReceivedColor(UPaintReceiverSimulationComponent* PaintReceiverSimulationComponent, UPaintReceiverPresentationComponent* PaintPresentationComponent, UColorItemConfig* ColorItem, FIntVector ImpactLocation, bool bPlayHitEffect);
    
};

