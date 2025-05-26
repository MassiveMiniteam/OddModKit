#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "ReplaceSimulationComponent.generated.h"

class AGridObject;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UReplaceSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyIfDoesntExist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRaycastTerrainForPresentation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGridObject> ReplacingClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> OnReplaceUnlockables;
    
public:
    UReplaceSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

