#pragma once
#include "CoreMinimal.h"
#include "SaveContainerBase.h"
#include "SaveContainer.generated.h"

UCLASS(Blueprintable)
class USaveContainer : public USaveContainerBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> SaveGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MainSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChunkCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FileSize;
    
public:
    USaveContainer();

};

