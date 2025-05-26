#pragma once
#include "CoreMinimal.h"
#include "Input/Events.h"
#include "NavRootWidget.h"
#include "NavRootCanvasWidget.generated.h"

class UCanvasPanel;
class UNavFocusPath;
class UNavUserWidget;
class UUserWidget;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UNavRootCanvasWidget : public UNavRootWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
    UCanvasPanel* CanvasPanel;
    
    UNavRootCanvasWidget();

    UFUNCTION(BlueprintCallable)
    void UnRegisterDragDropProcessor();
    
    UFUNCTION(BlueprintCallable)
    void RegisterDragDropProcessor();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnMouseButtonUpEvent(float MouseDistance, const FPointerEvent& MouseEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnMouseButtonDownEvent(const FPointerEvent& MouseEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFocusPathChanged(UNavFocusPath* Path);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHasVisibleChildren();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetChildrenCount() const;
    
    UFUNCTION(BlueprintCallable)
    void AddWidget(UUserWidget* UserWidget);
    
    UFUNCTION(BlueprintCallable)
    void AddChildToCanvas(UNavUserWidget* NavUserWidget);
    
};

