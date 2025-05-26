#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "OnTrainPolePlacementInputContextUpdatedDelegate.h"
#include "InputContextTrainPolePlacement.generated.h"

class ALocPlayerController;
class APresentationActor;
class ASimulationActor;
class UConstructableConfig;
class UInputActionData;
class UInputContextConstructionToolsCursor;

UCLASS(Blueprintable)
class LOC_API UInputContextTrainPolePlacement : public UInputContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTrainPolePlacementInputContextUpdated OnTrainPolePlacementInputContextUpdated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_RotateRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_SizeUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_SizeDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfigPole;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval HeightBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationActor* PreviewSimulationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APresentationActor* PreviewPresentationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
public:
    UInputContextTrainPolePlacement();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PoleFulfillsPlacementRules(ASimulationActor* IgnoreActor) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTargetRotationChanged(float NewTargetRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPoleHeightChanged(int32 OldHeight, int32 NewHeight);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInputAction_SizeUp(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_SizeDown(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Rotate(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APresentationActor* GetPreviewPresentationActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentTargetRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentHeight() const;
    
};

