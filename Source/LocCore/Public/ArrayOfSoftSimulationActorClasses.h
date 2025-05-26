#pragma once
#include "CoreMinimal.h"
#include "ArrayOfSoftSimulationActorClasses.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FArrayOfSoftSimulationActorClasses {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ASimulationActor>> Array;
    
    LOCCORE_API FArrayOfSoftSimulationActorClasses();
};

