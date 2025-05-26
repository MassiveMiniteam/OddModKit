#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "LocCorePlayerController.h"
#include "EBranchInputConsumedType.h"
#include "ModManifestShort.h"
#include "Templates/SubclassOf.h"
#include "LocPlayerController.generated.h"

class ASimulationPlayer;
class UInputDeviceMapping;
class USpawnPlayerSimulationCommand;
class UUIPlayerEntity;

UCLASS(Blueprintable)
class LOC_API ALocPlayerController : public ALocCorePlayerController {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUIPlayerEntity* UIPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FKey> CurrentlyConsumedKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpawnPlayerSimulationCommand> SpawnPlayerCommandType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint LastViewportSize;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCursorEnabled;
    
public:
    ALocPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateVibrationSupport(UInputDeviceMapping* CurrentDevice);
    
    UFUNCTION(BlueprintCallable)
    void UnsubscribeInputDeviceChange();
    
    UFUNCTION(BlueprintCallable)
    void SubscribeInputDeviceChange();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCursorEnabled(bool bState);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerAnswerModList(const TArray<FModManifestShort>& Mods);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSimulationPlayerSet(ASimulationPlayer* InSimulationPlayer);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnLoadingDone();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnInputDeviceChanged(UInputDeviceMapping* InputDevice);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCursorEnable(bool bState);
    
    UFUNCTION(BlueprintCallable)
    void MarkKeyConsumedThisFrame(FKey Key);
    
    UFUNCTION(BlueprintCallable)
    void IsConsumedKeyThisFrame(FKey Key, EBranchInputConsumedType& OutBranches);
    
public:
    UFUNCTION(BlueprintCallable)
    UUIPlayerEntity* GetUIPlayer() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FIntVector GetPlayerSpawnPosition();
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRequestModList();
    
};

