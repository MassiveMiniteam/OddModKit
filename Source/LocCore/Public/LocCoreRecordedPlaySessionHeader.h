#pragma once
#include "CoreMinimal.h"
#include "LocPlayerId.h"
#include "SaveGameOptions.h"
#include "SerializedSimulationObject.h"
#include "LocCoreRecordedPlaySessionHeader.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API ULocCoreRecordedPlaySessionHeader : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FLocPlayerId PlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsNewGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSaveGameOptions Options;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> SaveGameBytes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString SeedString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 OverrideSeed;
    
    ULocCoreRecordedPlaySessionHeader();

};

