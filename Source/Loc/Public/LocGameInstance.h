#pragma once
#include "CoreMinimal.h"
#include "LocCoreGameInstance.h"
#include "LocGameInstance.generated.h"

class ULocTestController;
class UProductEntitlementDataAsset;

UCLASS(Blueprintable, NonTransient)
class LOC_API ULocGameInstance : public ULocCoreGameInstance {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocTestController* TestController;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UProductEntitlementDataAsset*> EntitlementDataAssets;
    
    ULocGameInstance();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnApplySettings();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void LocToggleSpawnMetaData();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocToggleSpawnCellTiles();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocTestMessage();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocRunTest(const FString& TestName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocDestroyNiagaraComponents();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocApplyLunaGraphicSettings();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LocApplyGraphicSettings(int32 Value);
    
};

