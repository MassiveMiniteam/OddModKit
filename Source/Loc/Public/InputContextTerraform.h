#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "TerraformPosition.h"
#include "InputContextTerraform.generated.h"

class AActor;
class AGridHighlightHandler;
class ALocPlayerController;
class UConstructableConfig;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextConstructionToolsGamepadMovement;
class UInputContextSubsystem;
class UInputDeviceMapping;
class UMaterialInterface;
class UStaticMesh;

UCLASS(Blueprintable)
class LOC_API UInputContextTerraform : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlacementRadiusIndication;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDigUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateIndicationDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionPlace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionChangeMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputActionCancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridHighlightHandler* GridHighlightHandler_Terraform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridHighlightHandler* GridHighlightHandler_Hover_Valid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridHighlightHandler* GridHighlightHandler_Hover_Invalid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* GridPlacementRuleIndicatorMesh_Terraform_Up;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* GridPlacementRuleIndicatorMesh_Terraform_Down;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* GridPlacementRuleIndicatorMaterial_Terraform_Up;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* GridPlacementRuleIndicatorMaterial_Terraform_Down;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* GridPlacementRuleIndicatorMesh_Hover_Valid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* GridPlacementRuleIndicatorMaterial_Hover_Valid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* GridPlacementRuleIndicatorMesh_Hover_Invalid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* GridPlacementRuleIndicatorMaterial_Hover_Invalid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PreviousPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextSubsystem* InputContextSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextConstructionToolsGamepadMovement> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsGamepadMovement* GamepadMovementInputContext;
    
public:
    UInputContextTerraform();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTerraformPosition(const FTerraformPosition& TerraformPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInputPlace(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputDeviceChanged(UInputDeviceMapping* InputDevice);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInputChangeMode(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInputCancel(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHasNotEnoughResources();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedTerraformAt(const FTerraformPosition& TerraformPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedTerraform();
    
};

