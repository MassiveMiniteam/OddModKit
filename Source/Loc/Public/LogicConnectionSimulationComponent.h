#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "OnLogicEventDelegate.h"
#include "LogicConnectionSimulationComponent.generated.h"

class AGridNetwork;
class ALogicNetwork;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicConnectionSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLogicEvent OnSignalChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLogicEvent OnConnectionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLogicEvent OnWarningStateChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint GridOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* OwnerPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ALogicNetwork> MyNetwork;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsRefresh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bWarningAboutConnection;
    
public:
    ULogicConnectionSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RegisterOnNetwork();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnOwnerPositionChanged(UPositionSimulationComponent* PositionComponent, FIntVector LastPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnNetworkTilesChanged(TArray<FIntPoint> Tiles);
    
    UFUNCTION(BlueprintCallable)
    void OnNetworkConnectionChange();
    
    UFUNCTION(BlueprintCallable)
    void OnGridNetworkUpdated(AGridNetwork* GridNetwork);
    
    UFUNCTION(BlueprintCallable)
    void OnGridNetworkDestroyed(AGridNetwork* Instance);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasConnectionWarning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasConnectionIssue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStateAsBool() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRibbonStateAsInt() const;
    
    UFUNCTION(BlueprintCallable)
    ALogicNetwork* GetLogicNetwork() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetGridOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDefaultValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetActiveBitsOnRibbonChannel();
    
protected:
    UFUNCTION(BlueprintCallable)
    void CheckConnectionWarning();
    
};

