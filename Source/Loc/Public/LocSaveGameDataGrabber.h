#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LocPlayerId.h"
#include "SerializedSimulationObject.h"
#include "CellMetaDataBlockGridSaveGameItem.h"
#include "CellMetaDataBlockGridSaveGameItem_New.h"
#include "CellMetaDataCustomGroundLayerSaveGameItem.h"
#include "CellMetaDataCustomGroundLayerSaveGameItem_New.h"
#include "CellMetaDataCustomHeightSaveGameItem.h"
#include "CellMetaDataCustomHeightSaveGameItem_New.h"
#include "CellMetaDataCustomLandscapeLayerSaveGameItem.h"
#include "CellMetaDataCustomLandscapeLayerSaveGameItem_New.h"
#include "CellMetaDataCustomSnowHeightSaveGameItem.h"
#include "CellMetaDataCustomSnowHeightSaveGameItem_New.h"
#include "CellMetaDataSpawnActorSaveGameItem.h"
#include "CellMetaDataSpawnActorSaveGameItem_New.h"
#include "LocSubsystemSaveRecord.h"
#include "RampPositionRotationHeightSaveGameItem.h"
#include "RampPositionRotationHeightSaveGameItem_New.h"
#include "WorldCellMetaData.h"
#include "WorldCellMetaData_New.h"
#include "LocSaveGameDataGrabber.generated.h"

UCLASS(Blueprintable)
class ULocSaveGameDataGrabber : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 WorldSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGuid UniqueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString SaveSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FLocSubsystemSaveRecord> SubsystemSaveRecords;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> CellsIdsLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<bool> FogOfWar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<bool> LoadedMapMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FLocPlayerId HostPlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 HashCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FWorldCellMetaData> WorldCellMetaData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataSpawnActorSaveGameItem> CellMetaSpawnActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataBlockGridSaveGameItem> CellMetaBlockGrid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomGroundLayerSaveGameItem> CellMetaCustomGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomLandscapeLayerSaveGameItem> CellMetaCustomLandscape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomHeightSaveGameItem> CellMetaCustomHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomSnowHeightSaveGameItem> CellMetaCustomSnowHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FRampPositionRotationHeightSaveGameItem> Ramps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FWorldCellMetaData_New> WorldCellMetaData_Fast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataSpawnActorSaveGameItem_New> CellMetaSpawnActor_Fast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataBlockGridSaveGameItem_New> CellMetaBlockGrid_Fast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomGroundLayerSaveGameItem_New> CellMetaCustomGround_Fast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomLandscapeLayerSaveGameItem_New> CellMetaCustomLandscape_Fast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomHeightSaveGameItem_New> CellMetaCustomHeight_Fast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCellMetaDataCustomSnowHeightSaveGameItem_New> CellMetaCustomSnowHeight_Fast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FRampPositionRotationHeightSaveGameItem_New> Ramps_Fast;
    
    ULocSaveGameDataGrabber();

};

