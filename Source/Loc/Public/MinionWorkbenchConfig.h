#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MinionWorkbenchConfig.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FMinionWorkbenchConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* WorkbenchMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform BenchTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform LightTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlternateMinionPosition;
    
    LOC_API FMinionWorkbenchConfig();
};

