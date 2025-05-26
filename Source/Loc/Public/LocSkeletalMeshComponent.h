#pragma once
#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "LocSkeletalMeshComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULocSkeletalMeshComponent : public USkeletalMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAggregatedTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AggregatedPhaseCounts;
    
    ULocSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer);

};

