#pragma once
#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "RadialBox.generated.h"

UCLASS(Blueprintable)
class LOC_API URadialBox : public UPanelWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDistributeItemsEvenly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAllottedWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleBetweenItems;
    
public:
    URadialBox();

};

