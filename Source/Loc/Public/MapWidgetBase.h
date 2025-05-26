#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "NavUserWidget.h"
#include "Templates/SubclassOf.h"
#include "MapWidgetBase.generated.h"

class U2DScrollBox;
class UComponentRegistrationSubsystem;
class UMapIconSimulationComponent;
class UMapIconWidget;
class URegisteredSimulationComponent;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class LOC_API UMapWidgetBase : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMapIconWidget> PlayerMarkerWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultMapSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffscreenIconsScreenBorderDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMapIconWidget*> GenericIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox2D CachedPlayerAreaOnMap;
    
public:
    UMapWidgetBase();

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateWidgetPositionOnMap(UMapIconWidget* MapIconWidget, FIntVector WorldPosition, U2DScrollBox* MapScrollBox);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateMapIconPosition(UMapIconWidget* IconWidget, FIntVector WorldPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateGenericIconPositions_Native(bool bOnlyIfClampingToViewportIsNeeded, U2DScrollBox* MapScrollBox);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterIcons();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveMapIconWidget(UMapIconWidget* IconWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveMapIcon(UMapIconSimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void RegisterAndAddIcons();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMapIconComponentUnregistered(UComponentRegistrationSubsystem* Subsystem, URegisteredSimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void OnMapIconComponentRegistered(UComponentRegistrationSubsystem* Subsystem, URegisteredSimulationComponent* Component);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddMapIcon(UMapIconSimulationComponent* Component);
    
};

