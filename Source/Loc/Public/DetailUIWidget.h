#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "DetailUIWidget.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UDetailUIWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> SimulationActor;
    
public:
    UDetailUIWidget();

    UFUNCTION(BlueprintCallable)
    void Setup(ASimulationActor* InSimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetup(ASimulationActor* InSimulationActor);
    
};

