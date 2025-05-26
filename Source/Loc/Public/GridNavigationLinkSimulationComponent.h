#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GridNavigationJumpTarget.h"
#include "GridNavigationOverrideItem.h"
#include "GridNavigationLinkSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridNavigationLinkSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<bool> ConnectionMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGridNavigationOverrideItem> ModifyGridConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGridNavigationJumpTarget> GridJumpTargets;
    
    UGridNavigationLinkSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

