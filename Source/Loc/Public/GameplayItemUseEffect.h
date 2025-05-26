#pragma once
#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameplayItemUseEffect.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable)
class LOC_API UGameplayItemUseEffect : public UGameplayEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UInventoryComponent* TargetInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetInventoryIndex;
    
    UGameplayItemUseEffect();

};

