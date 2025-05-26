#pragma once
#include "CoreMinimal.h"
#include "LocSaveGameLoadOperation.generated.h"

USTRUCT(BlueprintType)
struct FLocSaveGameLoadOperation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCompatibleVersion;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 EditorSaveUnixTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsEditorVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CheckinNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GenerationVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDemo;
    
    LOCCORE_API FLocSaveGameLoadOperation();
};

