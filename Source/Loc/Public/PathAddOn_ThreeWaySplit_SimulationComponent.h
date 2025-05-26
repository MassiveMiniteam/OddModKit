#pragma once
#include "CoreMinimal.h"
#include "EOutDirectionStates.h"
#include "EOutDirections.h"
#include "PathAddOnSimulationComponent.h"
#include "PathDirectionDelegateDelegate.h"
#include "PathAddOn_ThreeWaySplit_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_ThreeWaySplit_SimulationComponent : public UPathAddOnSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathDirectionDelegate OnNextDirectionChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EOutDirections, EOutDirectionStates> CurrentDirectionVisualStates;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NextDirectionIndex;
    
public:
    UPathAddOn_ThreeWaySplit_SimulationComponent(const FObjectInitializer& ObjectInitializer);

};

