#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LocGlobalSaveGame.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocGlobalSaveGame : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FString> SaveGameNames;
    
    ULocGlobalSaveGame();

};

