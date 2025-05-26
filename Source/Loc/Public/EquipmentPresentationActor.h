#pragma once
#include "CoreMinimal.h"
#include "LocActor.h"
#include "EquipmentPresentationActor.generated.h"

UCLASS(Blueprintable)
class LOC_API AEquipmentPresentationActor : public ALocActor {
    GENERATED_BODY()
public:
    AEquipmentPresentationActor(const FObjectInitializer& ObjectInitializer);

};

