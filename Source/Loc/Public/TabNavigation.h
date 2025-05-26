#pragma once
#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "NavElementInterface.h"
#include "OnTabIndexChangedDelegate.h"
#include "UIEventReceiverInterface.h"
#include "TabNavigation.generated.h"

class UInputActionData;
class UNavFocusPath;
class UTabButtonRow;
class UTabContainer;

UCLASS(Blueprintable)
class LOC_API UTabNavigation : public UCanvasPanel, public INavElementInterface, public IUIEventReceiverInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTabIndexChanged OnTabIndexChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTabContainer* TabContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTabButtonRow* TabButtonRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 IndexToInitialize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentTabIndex;
    
public:
    UTabNavigation();

protected:
    UFUNCTION(BlueprintCallable)
    void SetTabIndex(int32 NewIndex);
    
    UFUNCTION(BlueprintCallable)
    void PrevTab(bool bFocusTab);
    
    UFUNCTION(BlueprintCallable)
    void NextTab(bool bFocusTab);
    
    UFUNCTION(BlueprintCallable)
    void Init();
    

    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION()
    void OnProcessInput(UNavFocusPath* Path, int32 PathIndex, UInputActionData* InputData) override PURE_VIRTUAL(OnProcessInput,);
    
};

