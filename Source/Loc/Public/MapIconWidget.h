#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EDestructionReason.h"
#include "Blueprint/UserWidget.h"
#include "EMapIconInteractionType.h"
#include "MapIconWidget_EventDelegate.h"
#include "MapIconWidget.generated.h"

class ASimulationActor;
class ASimulationPlayer;
class UImage;
class UMapIconSimulationComponent;
class UMapWidgetBase;
class UPositionSimulationComponent;
class USoundBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class LOC_API UMapIconWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapIconWidget_Event OnMapIconClicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D OutOfScreenMarkerPositionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D NormalizedMapPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutOfScreenMarkerRotationAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWidgetIsOutOfScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector WorldPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMapIconSimulationComponent> MapIconComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsMinimapIcon;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMapWidgetBase> MapWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UImage* ImageIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UImage* OutOfScreenMarker;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval ZoomLevelVisibilityRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClampPositionToViewport;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> PinSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> UnpinSound;
    
public:
    UMapIconWidget();

    UFUNCTION(BlueprintCallable)
    void UpdateVisibilityByZoomLevel(int32 NewZoomLevel);
    
    UFUNCTION(BlueprintCallable)
    void Unhover();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool ShouldClampPositionToViewport(ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RefreshPinnedStateWithSimulationValues();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnWorldPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnhovered();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSimulationActorShutDown(ASimulationActor* SimulationActor, EDestructionReason Reason);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPinnedStateChanged_Event(bool bObjectIsPinned, ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnPinnedStateChanged(bool bObjectIsPinned, ASimulationPlayer* SimulationPlayer);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMapIconLoaded();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInteractedFromMap(ASimulationPlayer* SimulationPlayer, EMapIconInteractionType InteractionType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHovered();
    
public:
    UFUNCTION(BlueprintCallable)
    void InteractFromMap(ASimulationPlayer* SimulationPlayer, EMapIconInteractionType InteractionType);
    
    UFUNCTION(BlueprintCallable)
    void Hover();
    
};

