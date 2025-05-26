#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ItemStack.h"
#include "ItemStackSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemStackSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemStack Item;
    
    UItemStackSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

