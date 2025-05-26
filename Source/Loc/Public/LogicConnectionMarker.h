#pragma once
#include "CoreMinimal.h"
#include "ChildPresentationActor.h"
#include "LogicConnectionMarker.generated.h"

class ULogicConnectionPresentationComponent;

UCLASS(Blueprintable)
class LOC_API ALogicConnectionMarker : public AChildPresentationActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicConnectionPresentationComponent> MyConnectionPresentationComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConnectionState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSignalState;
    
public:
    ALogicConnectionMarker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSignalState(bool SignalState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMarkerVisibility(bool bVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetConnectionState(bool State);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLogicToolUnhover();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLogicToolHover();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnLogicModeContextStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnLogicModeContextEnded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnected() const;
    
};

