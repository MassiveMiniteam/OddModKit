#pragma once
#include "CoreMinimal.h"
#include "ItemConfig.h"
#include "ItemConfigHat.generated.h"

class UStaticMesh;

UCLASS(Blueprintable)
class LOC_API UItemConfigHat : public UItemConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> HatMesh;
    
    UItemConfigHat();

};

