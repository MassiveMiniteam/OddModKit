#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "OnDemoBiomeRestrictionEventDelegate.h"
#include "SimulationTimerComponent.h"
#include "DemoBiomeRestrictionSimulationComponent.generated.h"

class UBiomeTrackerSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDemoBiomeRestrictionSimulationComponent : public USimulationTimerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDemoBiomeRestrictionEvent OnShowRestrictionWarning;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDemoBiomeRestrictionEvent OnHideRestrictionWarning;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDemoBiomeRestrictionEvent OnTeleportOutOfBiome;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DurationUntilTeleport;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBiomeTrackerSimulationComponent> BiomeTracker;
    
public:
    UDemoBiomeRestrictionSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

