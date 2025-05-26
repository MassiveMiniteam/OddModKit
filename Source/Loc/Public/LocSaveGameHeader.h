#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "ModManifestShort.h"
#include "LocSaveGameHeader.generated.h"

UCLASS(Blueprintable)
class ULocSaveGameHeader : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString Version;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int64 EditorSaveUnixTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FModManifestShort> InstalledMods;
    
    ULocSaveGameHeader();

};

