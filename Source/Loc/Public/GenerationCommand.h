#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGenerationCommandType.h"
#include "GenerationCommand.generated.h"

class UBiomeCellInstance;
class UGridChunk;
class UObject;

USTRUCT(BlueprintType)
struct FGenerationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenerationCommandType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Generator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint Pos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellInstance* BiomeCellInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridChunk* Chunk;
    
    LOC_API FGenerationCommand();
};

