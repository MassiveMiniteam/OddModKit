#pragma once
#include "CoreMinimal.h"
#include "LocSubsystemSaveRecord.generated.h"

USTRUCT(BlueprintType)
struct FLocSubsystemSaveRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UClass* Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> Bytes;
    
    LOC_API FLocSubsystemSaveRecord();
};

