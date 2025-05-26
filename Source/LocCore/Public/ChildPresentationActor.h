#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "LocActor.h"
#include "PresentationObjectInterface.h"
#include "ChildPresentationActor.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API AChildPresentationActor : public ALocActor, public IPresentationObjectInterface {
    GENERATED_BODY()
public:
    AChildPresentationActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnPresentationPreBegin_Manually(bool bLoading);
    
    UFUNCTION(BlueprintCallable)
    void OnPresentationEnd_Manually(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable)
    void OnPresentationBegin_Manually(bool bLoading);
    

    // Fix for true pure virtual functions not being implemented
};

