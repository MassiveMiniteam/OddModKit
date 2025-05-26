#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EDestructionReason.h"
#include "ELoadBalancerTaskPriority.h"
#include "EValidityState.h"
#include "Fixed.h"
#include "LocActor.h"
#include "SimulationActorEventDelegate.h"
#include "SimulationActor.generated.h"

class AActor;
class ASimulationActor;
class IPresentationObjectInterface;
class UPresentationObjectInterface;
class UPresentationActorComponent;
class USimulationActorComponent;
class UTexture2D;

UCLASS(Blueprintable)
class LOCCORE_API ASimulationActor : public ALocActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FSimulationActorPresentationSpawnDelegate, ASimulationActor*, Actor);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableTick;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TScriptInterface<IPresentationObjectInterface> PresentationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USimulationActorComponent*> SimulationActorComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPresentationActorComponent*> PresentationActorComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USimulationActorComponent*> PresentationSimActorComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USimulationActorComponent*> TickingSimulationActorComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USimulationActorComponent*> TickingSimulationActorComponentsToRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> LocIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerformance_OnTickSimulationImplemented;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreInPlacementRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bShouldSave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsGenerated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepAliveWhenSpawnedProcedurally;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRegistered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPooled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsSleeping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyPresentationOnSimEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlySpawnPresentationOnServer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPoolSimulationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> PresentationActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPoolPresentationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAsyncSpawnPresentationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELoadBalancerTaskPriority AsyncSpawnPresentationPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInitializedPresentation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationActorEvent OnSimulationActorShutDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPresentationLoadRequested;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasSetupPresentation;
    
public:
    ASimulationActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetPresentationActor(TScriptInterface<IPresentationObjectInterface> PresentationObjectInterface);
    
    UFUNCTION(BlueprintCallable)
    void SetEnableTick(bool bEnable);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTickSimulation(FFixed DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimulationPreBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimulationEnd(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimulationBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable)
    void OnlySebastianIsAllowedToUseThisFunction(FText Name, FText Description, TSoftObjectPtr<UTexture2D> Icon);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetRichTextId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetPresentationActorChecked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    AActor* GetPresentationActorBranched(EValidityState& ValidityState) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TScriptInterface<IPresentationObjectInterface> GetPresentationActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfTickingComponents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetLocName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetLocIcon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetLocDescription() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetIsTickingEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsPooled() const;
    
};

