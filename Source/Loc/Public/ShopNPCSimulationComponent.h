#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ItemStack.h"
#include "ShopNPCSimulationComponent.generated.h"

class UNPCConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UShopNPCSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNPCConfig* NPCConfig;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> CostsVolume;
    
public:
    UShopNPCSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

