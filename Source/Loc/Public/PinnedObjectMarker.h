#pragma once
#include "CoreMinimal.h"
#include "LocCoreSavable.h"
#include "SimulationActor.h"
#include "PinnedObjectMarker.generated.h"

class UMapIconSimulationComponent;
class UPlayerIdentificationSimulationReferenceComponent;
class UPositionAttachmentSimulationComponent;
class UPositionSimulationComponent;

UCLASS(Blueprintable)
class LOC_API APinnedObjectMarker : public ASimulationActor, public ILocCoreSavable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerIdentificationSimulationReferenceComponent* PlayerIdentificationReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionAttachmentSimulationComponent* PositionAttachmentSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMapIconSimulationComponent> TargetMapIconComponent;
    
public:
    APinnedObjectMarker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTarget(UMapIconSimulationComponent* InMapIconComponent, UPositionSimulationComponent* InPositionComponent);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

