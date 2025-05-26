#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "HighlightPresentationComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UHighlightPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableOnBeginPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableOnPresentationBegin;
    
public:
    UHighlightPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHighlightEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHighlightDisabled();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyHighlighted() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableHighlight(bool bState);
    
};

