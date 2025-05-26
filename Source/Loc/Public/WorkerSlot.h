#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "WorkerSlot.generated.h"

class ULogicInputSimulationComponent;

USTRUCT(BlueprintType)
struct FWorkerSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference LogicInputRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput;
    
    LOC_API FWorkerSlot();
};

