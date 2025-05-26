#pragma once
#include "CoreMinimal.h"
#include "ProceduralWorldGenerator.h"
#include "WorldGenerator_AddBorder.generated.h"

class UBiomeConfig;
class UProceduralGeneratorCondition;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UWorldGenerator_AddBorder : public UProceduralWorldGenerator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeConfig* BlockedBiomeConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockedCellsBottom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockedCellsLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockedCellsRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockedCellsTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProceduralGeneratorCondition* Condition;
    
    UWorldGenerator_AddBorder();

};

