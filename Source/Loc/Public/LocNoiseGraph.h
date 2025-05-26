#pragma once
#include "CoreMinimal.h"
#include "NoiseGraph.h"
#include "LocNoiseGraph.generated.h"

class UNoiseGraphNodeMasterBase;

UCLASS(Blueprintable)
class LOC_API ULocNoiseGraph : public UNoiseGraph {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNoiseGraphNodeMasterBase* NodeMaster;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseBiomeSeed;
    
    ULocNoiseGraph();

};

