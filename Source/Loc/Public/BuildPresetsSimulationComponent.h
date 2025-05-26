#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "BuildPreset.h"
#include "BuildPresetSelectionChangedEventDelegate.h"
#include "BuildPresetsSimulationComponent.generated.h"

class IBuildToolAssignable;
class UBuildToolAssignable;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBuildPresetsSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildPresetSelectionChangedEvent OnPresetsChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultNumRows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UUnlockableDataAsset*, TScriptInterface<IBuildToolAssignable>> UnlockableActionToBuildToolAssignables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* BuildPresetUnlockable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FBuildPreset> BuildPresets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SelectedRowIndex;
    
public:
    UBuildPresetsSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnItemUnlocked(UUnlockableDataAsset* UnlockableDataAsset);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRowEmpty(int32 Row) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRowEditable(int32 Row);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAssignableInRow(const TScriptInterface<IBuildToolAssignable>& BuildToolAssignable, int32 Row);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSelectedRowIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBuildPreset GetSelectedPreset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPresetsMaxIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPresetsAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FBuildPreset> GetPresets() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAddAssignableToRow(const TScriptInterface<IBuildToolAssignable>& BuildToolAssignable, int32 Row);
    
};

