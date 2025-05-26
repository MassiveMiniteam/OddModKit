#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "ELifeTimeEndEvent.h"
#include "SimulationTimerComponent.h"
#include "LifeTimeSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULifeTimeSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed LifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELifeTimeEndEvent OnLifeTimeEnds;
    
public:
    ULifeTimeSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

