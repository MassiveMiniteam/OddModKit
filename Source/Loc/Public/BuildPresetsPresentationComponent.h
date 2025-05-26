#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "BuildPreset.h"
#include "BuildToolPresetsPresentationEventDelegate.h"
#include "BuildToolPresetsRowSelectPresentationEventDelegate.h"
#include "BuildPresetsPresentationComponent.generated.h"

class IBuildToolAssignable;
class UBuildToolAssignable;
class UBuildPresetsSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBuildPresetsPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildToolPresetsPresentationEvent OnBuildToolPresetsChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildToolPresetsRowSelectPresentationEvent OnNewRowSelected;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBuildPreset> BuildPresets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedRowIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBuildPresetsSimulationComponent* BuildPresetsSimulationComponent;
    
public:
    UBuildPresetsPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnBuildPresetsSimulationUpdated(UBuildPresetsSimulationComponent* Component, int32 Index, FBuildPreset Preset, bool bUpdatePresentation);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAssignableInRow(const TScriptInterface<IBuildToolAssignable>& BuildToolAssignable, int32 Row);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBuildPreset GetSelectedPreset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentRowIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FBuildPreset> GetBuildPresets();
    
};

