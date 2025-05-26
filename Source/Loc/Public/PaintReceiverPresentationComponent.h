#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "PresentationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "PaintReceiverPresentationComponent.generated.h"

class UColorItemConfig;
class UPaintReceiverPresentationStrategy;
class UPaintReceiverSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPaintReceiverPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UPaintReceiverPresentationStrategy>> PaintReceiverStrategies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPaintReceiverSimulationComponent* PaintReceiverSimulationComponent;
    
public:
    UPaintReceiverPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnColorChanged(UPaintReceiverSimulationComponent* InPaintReceiverSimulationComponent, UColorItemConfig* ColorItem, FIntVector ImpactLocation, FFixed Delay);
    
};

