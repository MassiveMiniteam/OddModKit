#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "PaintReceiverEventDelegate.h"
#include "PaintReceiverSimulationComponent.generated.h"

class UColorItemConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPaintReceiverSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPaintReceiverEvent OnColorChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UColorItemConfig* CurrentColorItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UColorItemConfig* DefaultColorItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentDelay;
    
public:
    UPaintReceiverSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UColorItemConfig* ReturnCurrentOrDefaultColor();
    
    UFUNCTION(BlueprintCallable)
    void Reset(FIntVector ImpactLocation, FFixed Delay);
    
    UFUNCTION(BlueprintCallable)
    void Paint(UColorItemConfig* ColorItem, FIntVector ImpactLocation, FFixed Delay);
    

    // Fix for true pure virtual functions not being implemented
};

