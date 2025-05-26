#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActor.h"
#include "CliffConnection.h"
#include "EGridDirectionVisualizationType.h"
#include "DragPlaceablePresentationActor.generated.h"

class UGridNetworkSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ADragPlaceablePresentationActor : public APresentationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRaycastingForPreview;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGridDirectionVisualizationType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RotationInDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOnCliff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCliffConnection> CliffConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CliffHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxCliffHeightDiff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasCliffConnection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLowerRampCorner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOnRamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTopPartOfRamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint RampDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsiderRampsAsCliffs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGridNetworkSimulationComponent* GridNetworkSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> MyConnectionsCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInGhostMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentPlacmentState;
    
public:
    ADragPlaceablePresentationActor(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdatePlacementStateEvent(int32 NoneBlockedFree);
    
public:
    UFUNCTION(BlueprintCallable)
    void UpdatePlacementState(int32 NoneBlockedFree);
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateGridConnectionType(const TArray<FIntPoint>& NewConnections);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateConnection(const TArray<FIntPoint>& NewConnections);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetPlacementOrderIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetGhostMode(bool bIsGhostMode);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnGridNetworkUpdated(UGridNetworkSimulationComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static bool GetGridConnectionType(const TArray<FIntPoint>& Connections, EGridDirectionVisualizationType& TypeOut, int32& RotationInDegreesOut);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FCliffConnection> GetCliffConnections();
    
};

