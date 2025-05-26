#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EMapIconInteractionType.h"
#include "TeleporterComponent_Bool_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "TeleporterSimulationComponent.generated.h"

class ASimulationPlayer;
class UMapIconSimulationComponent;
class UTeleporterStrategy;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTeleporterSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTeleporterComponent_Bool_Event OnTeleportAvailabilityStateChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTeleporterStrategy> TeleporterStrategy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowLoadingScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBindMapIconComponent;
    
public:
    UTeleporterSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TeleportLocalPlayerCharacterToThis();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInteractedWithMapIcon(UMapIconSimulationComponent* MapIcon, ASimulationPlayer* Player, EMapIconInteractionType InteractionType);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetStatusText() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeUsed() const;
    
};

