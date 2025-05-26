#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralGeneratorCondition.h"
#include "ProceduralGeneratorCondition_DistanceToBorder.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UProceduralGeneratorCondition_DistanceToBorder : public UProceduralGeneratorCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 DistanceBottomRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 DistanceLeftRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 DistanceRightRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 DistanceTopRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 DistanceToBorderRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector2 DistanceToStart;
    
public:
    UProceduralGeneratorCondition_DistanceToBorder();

};

