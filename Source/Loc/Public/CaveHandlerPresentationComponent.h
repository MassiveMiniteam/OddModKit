#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "CaveHandlerPresentationComponent.generated.h"

class UBiomeCellInstance;
class UCameraEffectPresentationComponent;
class UDynamicTexture;
class UMaterialInstanceDynamic;
class UPostProcessComponent;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCaveHandlerPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraEffectPresentationComponent* CameraEffectPresentationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* BiomeMaskMaterialDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicTexture* DynamicBiomeMaskTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* PostProcessComponent;
    
public:
    UCaveHandlerPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateCaveEnterEvent();
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterial(UMaterialInstanceDynamic* NewMaterial);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerLeftCave();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerEnteredCave();
    
    UFUNCTION(BlueprintCallable)
    void OnBiomeEffectChanged(UCameraEffectPresentationComponent* InCameraEffectPresentationComponent, UBiomeCellInstance* PreviousCell, UBiomeCellInstance* NewCell);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetDynamicMaskTexture();
    
};

