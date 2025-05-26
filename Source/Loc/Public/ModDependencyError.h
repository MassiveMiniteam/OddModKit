#pragma once
#include "CoreMinimal.h"
#include "ModManifestShort.h"
#include "ModDependencyError.generated.h"

class UModInstance;

USTRUCT(BlueprintType)
struct FModDependencyError {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModManifestShort ManifestShort;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsDisable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsInstall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModInstance* ModInstance;
    
    LOC_API FModDependencyError();
};

