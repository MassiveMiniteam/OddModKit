#pragma once
#include "CoreMinimal.h"
#include "EquipmentPresentationActorSlot.generated.h"

class APresentationActor;

USTRUCT(BlueprintType)
struct FEquipmentPresentationActorSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APresentationActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnablePresentation;
    
    LOC_API FEquipmentPresentationActorSlot();
};

