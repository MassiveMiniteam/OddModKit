#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "WorldGenerationInfo.h"
#include "LocSaveGameWorldGenerationSaveItem.generated.h"

UCLASS(Blueprintable)
class ULocSaveGameWorldGenerationSaveItem : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FWorldGenerationInfo WorldGenerationInfo;
    
    ULocSaveGameWorldGenerationSaveItem();

};

