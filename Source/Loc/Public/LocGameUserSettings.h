#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "EAntiAliasingType.h"
#include "EDLSSMode.h"
#include "EFSRMode.h"
#include "ELumen.h"
#include "ERenderMode.h"
#include "EVSyncType.h"
#include "LocGameUserSettings.generated.h"

class ULocGameUserSettings;

UCLASS(Blueprintable, Config=Engine)
class LOC_API ULocGameUserSettings : public UGameUserSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInitialSetupDone;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVSyncType VSyncType;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAntiAliasingType AntiAliasingType;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDLSSMode DLSSMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFSRMode FSRMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ScreenPercentage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELumen LumenEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GammaValue;
    
public:
    ULocGameUserSettings();

    UFUNCTION(BlueprintCallable)
    static bool WouldChangeRHI();
    
    UFUNCTION(BlueprintCallable)
    void TriggerUIUpdateDelegate();
    
    UFUNCTION(BlueprintCallable)
    void SetVSyncType(EVSyncType Value);
    
    UFUNCTION(BlueprintCallable)
    void SetScreenPercentage(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetRenderMode(ERenderMode Value);
    
    UFUNCTION(BlueprintCallable)
    void SetLumen(ELumen Value);
    
    UFUNCTION(BlueprintCallable)
    void SetGammaValue(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetFSRMode(EFSRMode Value);
    
    UFUNCTION(BlueprintCallable)
    void SetDLSSMode(EDLSSMode Value);
    
    UFUNCTION(BlueprintCallable)
    void SetAntiAliasing(EAntiAliasingType Value);
    
    UFUNCTION(BlueprintCallable)
    bool IsLumenEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDirectX12();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EVSyncType GetVSyncType();
    
    UFUNCTION(BlueprintCallable)
    static FText GetSupportedRHINames(ERenderMode enumInput);
    
    UFUNCTION(BlueprintCallable)
    static TArray<ERenderMode> GetSupportedRenderModes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EAntiAliasingType> GetSupportedAntiAliasingTypes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetScreenPercentage();
    
    UFUNCTION(BlueprintCallable)
    static ERenderMode GetRHIEnum();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ULocGameUserSettings* GetLocGameUserSettings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetIniRHI();
    
    UFUNCTION(BlueprintCallable)
    static ERenderMode GetIniEnum();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetHardwareInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGammaValue();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EFSRMode GetFSRMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<float> GetFramerateLimits();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FText> GetFramerateLimitNames();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetFramerateLimitDisplayName(float Limit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDLSSMode GetDLSSMode();
    
    UFUNCTION(BlueprintCallable)
    TArray<FText> GetAntiAliasingDisplayNames();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAntiAliasingDisplayName(EAntiAliasingType AAType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAntiAliasingType GetAntiAliasing();
    
};

