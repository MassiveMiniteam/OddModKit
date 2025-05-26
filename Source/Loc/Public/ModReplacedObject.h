#pragma once
#include "CoreMinimal.h"
#include "ModReplacedObject.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FModReplacedObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Path;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Object;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Bytes;
    
    LOC_API FModReplacedObject();
};

