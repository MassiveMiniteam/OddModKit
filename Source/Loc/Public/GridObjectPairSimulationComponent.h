#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "GridObjectPairEventDelegate.h"
#include "GridObjectPairGridObjectEventDelegate.h"
#include "GridObjectPairSimulationComponent.generated.h"

class AGridObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridObjectPairSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridObjectPairGridObjectEvent OnGridObjectConnectionMade;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridObjectPairEvent OnGridObjectDisconnected;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AGridObject> RelatedGridObject;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval DistanceToRelatedActor;
    
public:
    UGridObjectPairSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetRelatedGridObject(AGridObject* GridObject);
    
    UFUNCTION(BlueprintPure)
    FFloatInterval GetRequiredDistanceToRelatedActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AGridObject* GetRelatedGridObject() const;
    
};

