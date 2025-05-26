#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SharedActorContainer.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API USharedActorContainer : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> Actors;
    
    USharedActorContainer();

};

