#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EDestructionReason.h"
#include "EMapIconInteractionType.h"
#include "MapIconPlayerInteraction_EventDelegate.h"
#include "ObjectPinStateChangedEventDelegate.h"
#include "RegisteredSimulationComponent.h"
#include "Templates/SubclassOf.h"
#include "MapIconSimulationComponent.generated.h"

class APinnedObjectMarker;
class ASimulationActor;
class ASimulationPlayer;
class UMapIconConditionStrategy;
class UMapIconWidget;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMapIconSimulationComponent : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectPinStateChangedEvent OnPinObjectStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapIconPlayerInteraction_Event OnPlayerInteractedWithMapIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D MinimapVisibleZoomRange;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> MapIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBePinned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<APinnedObjectMarker*> PinnedObjectMarkers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMapIconWidget> WidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UMapIconConditionStrategy>> Conditions;
    
public:
    UMapIconSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnMarkerShutdown(ASimulationActor* InSimulationActor, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInteractedFromMap_Event(ASimulationPlayer* SimulationPlayer, EMapIconInteractionType InteractionType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectCurrentlyPinnedOnMapForPlayer(ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void InteractFromWorldMap(ASimulationPlayer* Player, EMapIconInteractionType InteractionType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetMapIconTexture() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreAllConditionsFulfilled() const;
    
};

