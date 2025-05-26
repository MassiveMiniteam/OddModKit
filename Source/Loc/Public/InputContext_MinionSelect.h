#pragma once
#include "CoreMinimal.h"
#include "InputContext.h"
#include "InputContext_MinionSelect.generated.h"

class ASimulationActor;

UCLASS(Abstract, Blueprintable)
class LOC_API UInputContext_MinionSelect : public UInputContext {
    GENERATED_BODY()
public:
    UInputContext_MinionSelect();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ASimulationActor* GetNextDeplyedAndThrowAbleMinion() const;
    
};

