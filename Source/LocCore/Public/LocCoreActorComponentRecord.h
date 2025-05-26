#pragma once
#include "CoreMinimal.h"
#include "LocCoreActorComponentRecord.generated.h"

USTRUCT(BlueprintType)
struct FLocCoreActorComponentRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Data;
    
    LOCCORE_API FLocCoreActorComponentRecord();
};

