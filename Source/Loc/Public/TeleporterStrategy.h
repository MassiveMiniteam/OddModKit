#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TeleporterStrategy.generated.h"

class UTeleporterSimulationComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UTeleporterStrategy : public UObject {
    GENERATED_BODY()
public:
    UTeleporterStrategy();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTeleportStarted(const UTeleporterSimulationComponent* TeleporterComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetStatusText(const UTeleporterSimulationComponent* TeleporterComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool AreConditionsFulfilled(const UTeleporterSimulationComponent* TeleporterComponent) const;
    
};

