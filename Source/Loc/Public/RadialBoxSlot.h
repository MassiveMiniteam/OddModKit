#pragma once
#include "CoreMinimal.h"
#include "Components/PanelSlot.h"
#include "RadialBoxSlot.generated.h"

UCLASS(Blueprintable)
class LOC_API URadialBoxSlot : public UPanelSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotationShouldFollowCircle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleOnCircle;
    
    URadialBoxSlot();

};

