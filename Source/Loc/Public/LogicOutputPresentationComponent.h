#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "LogicConnectionPresentationComponent.h"
#include "LogicOutputPresentationComponent.generated.h"

class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicOutputPresentationComponent : public ULogicConnectionPresentationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TargetLogicOutputRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicOutputSimulationComponent* TargetLogicOutput;
    
public:
    ULogicOutputPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ScheduleSignal(FName Channel, int32 Value);
    
};

