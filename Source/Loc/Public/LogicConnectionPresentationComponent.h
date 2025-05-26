#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "Templates/SubclassOf.h"
#include "LogicConnectionPresentationComponent.generated.h"

class AActor;
class ALogicConnectionMarker;
class UChildActorComponent;
class UEventDataAssetWithState;
class ULogicConnectionSimulationComponent;
class UPositionSimulationComponent;
class UPrimitiveComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicConnectionPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ALogicConnectionMarker> LogicMarkerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> LogicWarningClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LogicMarkerOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WarningMarkerOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor ConnectorColorForEditorPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideEditorPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, UStaticMeshComponent*> PositionToEdgeMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowConnectionMarkerInPreview;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventDataAssetWithState* LogicLayerEventDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* LogicMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* WarningMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* OwnerPositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ALogicConnectionMarker> LogicMarkerActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIndicateConnectionsOnEdges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* EdgeMarkerMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EdgeMarkerPrimitiveDataIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> DirectionsToIndicate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagForIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SignalPrimitiveDataIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> IndicatorPrimitiveComponenents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> ConnectionIndicators;
    
public:
    ULogicConnectionPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateIndicationOnTile();
    
    UFUNCTION(BlueprintCallable)
    void OnWarningChanged(ULogicConnectionSimulationComponent* Input);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSignalChanged(ULogicConnectionSimulationComponent* Connection);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnLogicNetworkChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnLogicLayerVisiblityChanged(UEventDataAssetWithState* EventDataAssetWithState, bool bState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLeaveLogicMode();
    
    UFUNCTION(BlueprintCallable)
    void OnGridObjectPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnterLogicMode();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnConnectionChanged(ULogicConnectionSimulationComponent* Connection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTargetPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULogicConnectionSimulationComponent* GetSimulationComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ALogicConnectionMarker* GetConnectionMarker() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetActiveBitsOnRibbonChannel();
    
};

