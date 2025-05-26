#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CursorLockPositionPresentationComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UCursorLockPositionPresentationComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UCursorLockPositionPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Show();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Select();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Hide();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Deselect();
    
};

