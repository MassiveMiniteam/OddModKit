#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Components/SceneComponent.h"
#include "ItemStack.h"
#include "Templates/SubclassOf.h"
#include "SimulationActorPreset.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USimulationActorPreset : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> SimulationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector PositionAsIntVector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> ItemsToAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InventoryReference;
    
    USimulationActorPreset(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FIntVector GetPositionAsIntVector();
    
};

