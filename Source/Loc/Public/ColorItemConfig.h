#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "ItemConfig.h"
#include "ColorItemConfig.generated.h"

UCLASS(Blueprintable)
class LOC_API UColorItemConfig : public UItemConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag MinionColorTag;
    
    UColorItemConfig();

};

