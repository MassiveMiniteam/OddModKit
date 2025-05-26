#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "NPCSimulationComponent.generated.h"

class UBiomeConfig;
class UQuestOverviewCategory;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UNPCSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* Biome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VisualSortIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestOverviewCategory* QuestOverviewCategory;
    
    UNPCSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

