#pragma once
#include "CoreMinimal.h"
#include "SimulationHashRecordItem.h"
#include "SimulationHashRecord.generated.h"

USTRUCT(BlueprintType)
struct FSimulationHashRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsSimpleHash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSimulationHashRecordItem> HashMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> PathStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString CurrentPathStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFullHash;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint32 CompleteHash;
    
    LOCCORE_API FSimulationHashRecord();
};

