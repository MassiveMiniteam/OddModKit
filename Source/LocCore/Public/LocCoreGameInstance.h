#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/GameInstance.h"
#include "LocCoreGameInstance.generated.h"

class UAssetDatabase;
class ULocCoreSaveGame;

UCLASS(Blueprintable, NonTransient)
class LOCCORE_API ULocCoreGameInstance : public UGameInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAssetDatabase* AssetDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsComingFromActivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLocTestMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EObjectTypeQuery> LandscapeObjectTypeQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EObjectTypeQuery> WorldDynamicTypeQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocCoreSaveGame* CurrentSaveGame;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TicksUntilHide;
    
public:
    ULocCoreGameInstance();

    UFUNCTION(BlueprintCallable)
    void ShowLoadingScreen();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowLoadingScreen();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHideLoadingScreen();
    
public:
    UFUNCTION(BlueprintCallable)
    void HideLoadingScreen();
    
};

