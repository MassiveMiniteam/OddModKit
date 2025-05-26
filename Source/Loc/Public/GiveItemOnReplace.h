#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "ItemStack.h"
#include "GiveItemOnReplace.generated.h"

class ASimulationPlayer;
class UReplaceGridObjectOnConditionComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGiveItemOnReplace : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference ReplaceComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Items;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDropOnGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReplaceGridObjectOnConditionComponent* ReplaceComponent;
    
public:
    UGiveItemOnReplace(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnReplace(UReplaceGridObjectOnConditionComponent* Component, ASimulationPlayer* Player);
    
};

