#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "LogicConnectionPresentationComponent.h"
#include "LogicInputPresentationComponent.generated.h"

class ULogicInputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicInputPresentationComponent : public ULogicConnectionPresentationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TargetLogicInputRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicInputSimulationComponent* TargetLogicInput;
    
public:
    ULogicInputPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

