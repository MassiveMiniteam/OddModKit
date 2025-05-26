#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ArrayOfSimulationActorClasses.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FArrayOfSimulationActorClasses {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> Array;
    
    LOCCORE_API FArrayOfSimulationActorClasses();
};

