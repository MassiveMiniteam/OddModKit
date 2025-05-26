#pragma once
#include "CoreMinimal.h"
#include "GridObjectCopyData.h"
#include "PayAndSpawnGridObjectCommand.h"
#include "PayAndPasteGridObjectCommand.generated.h"

UCLASS(Blueprintable)
class LOC_API UPayAndPasteGridObjectCommand : public UPayAndSpawnGridObjectCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGridObjectCopyData GridObjectCopyData;
    
    UPayAndPasteGridObjectCommand();

};

