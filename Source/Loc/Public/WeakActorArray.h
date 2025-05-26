#pragma once
#include "CoreMinimal.h"
#include "WeakActorArray.generated.h"

class ASimulationActor;

USTRUCT(BlueprintType)
struct FWeakActorArray {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ASimulationActor>> Actors;
    
    LOC_API FWeakActorArray();
};

