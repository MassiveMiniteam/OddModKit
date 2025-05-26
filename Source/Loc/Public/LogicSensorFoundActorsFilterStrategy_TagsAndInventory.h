#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "LogicSensorFoundActorsFilterStrategy.h"
#include "LogicSensorFoundActorsFilterStrategy_TagsAndInventory.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API ULogicSensorFoundActorsFilterStrategy_TagsAndInventory : public ULogicSensorFoundActorsFilterStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ForbiddenTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryAssociatedClassesFilter;
    
public:
    ULogicSensorFoundActorsFilterStrategy_TagsAndInventory();

};

