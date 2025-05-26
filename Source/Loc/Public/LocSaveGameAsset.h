#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "LocSaveGameAsset.generated.h"

class ULocSaveGame;

UCLASS(Blueprintable)
class LOC_API ULocSaveGameAsset : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Meta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Data;
    
    ULocSaveGameAsset();

    UFUNCTION(BlueprintCallable)
    ULocSaveGame* GetSaveGame();
    
};

