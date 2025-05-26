#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "PresentationActorComponent.h"
#include "MinionAssignCursorSnapPresentationComponent.generated.h"

class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMinionAssignCursorSnapPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MinionTagsWhiteList;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SnapPositionReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SnapPositionSceneComponent;
    
public:
    UMinionAssignCursorSnapPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool ShouldSnapToActiveMinion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetSnapPosition();
    
};

