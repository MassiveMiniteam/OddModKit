#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "OnNewBiomeEffectDelegate.h"
#include "PostProcessBlendData.h"
#include "Templates/SubclassOf.h"
#include "CameraEffectPresentationComponent.generated.h"

class ALocPostProcessingVolume;
class UBiomeCellInstance;
class UBiomeConfig;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCameraEffectPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNewBiomeEffect OnNewBiomeEffect;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RVTResetDistanceInGridUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostProcessBlendDurationInSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeCellInstance* CachedBiomeCellInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LastRVTPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ALocPostProcessingVolume> LastPostProcessActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LocalPositionCheckDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessBlendData ActivePostProcessVolumeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostProcessBlendData> LastPostProcessVolumeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionSimulationComponent;
    
public:
    UCameraEffectPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RestartRVT();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetupForLocalPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnResetRVTPosition(FVector NewWorldPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnGridPositionChanged(UPositionSimulationComponent* SimulationComponent, FIntPoint LastPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBiomeChanged(UBiomeConfig* FromBiome, UBiomeConfig* ToBiome);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ALocPostProcessingVolume* GetActivePostProcessVolume() const;
    
};

