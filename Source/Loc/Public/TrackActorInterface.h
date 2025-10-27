#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TrackActorInterface.generated.h"

class USplineComponent;

UINTERFACE(Blueprintable)
class UTrackActorInterface : public UInterface {
    GENERATED_BODY()
};

class ITrackActorInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    USplineComponent* GetSplineComponent() const;
    
};

