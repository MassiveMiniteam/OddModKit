#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LocGlobalProfileSave.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocGlobalProfileSave : public USaveGame {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> ProfileBytes;
    
public:
    ULocGlobalProfileSave();

};

