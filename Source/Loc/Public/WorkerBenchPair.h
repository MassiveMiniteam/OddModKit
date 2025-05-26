#pragma once
#include "CoreMinimal.h"
#include "WorkerBenchPair.generated.h"

class USkeletalMeshComponent;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FWorkerBenchPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* MinionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* WorkbenchComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorkTimer;
    
    LOC_API FWorkerBenchPair();
};

