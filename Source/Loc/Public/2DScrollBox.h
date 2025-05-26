#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Layout/Margin.h"
#include "Styling/SlateTypes.h"
#include "Styling/SlateTypes.h"
#include "Components/SlateWrapperTypes.h"
#include "Components/PanelWidget.h"
#include "E2DScrollMouseDragButton.h"
#include "EDescendantScroll2DDestination.h"
#include "OnUserScrolledVectorEventDelegate.h"
#include "2DScrollBox.generated.h"

class UWidget;

UCLASS(Blueprintable)
class LOC_API U2DScrollBox : public UPanelWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScrollBoxStyle WidgetStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScrollBarStyle WidgetBarStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESlateVisibility ScrollBarVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScrollbarThickness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin ScrollBarPadding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysShowScrollbar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysShowScrollbarTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowOverscroll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDescendantScroll2DDestination NavigationDestination;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D NavigationScrollPadding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EScrollWhenFocusChanges ScrollWhenFocusChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowMouseDragScrolling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    E2DScrollMouseDragButton MouseDragButton;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUserScrolledVectorEvent OnUserScrolled;
    
    U2DScrollBox();

    UFUNCTION(BlueprintCallable)
    void SetScrollWhenFocusChanges(EScrollWhenFocusChanges NewScrollWhenFocusChanges);
    
    UFUNCTION(BlueprintCallable)
    void SetScrollOffset(FVector2D NewScrollOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetScrollbarVisibility(ESlateVisibility NewScrollBarVisibility);
    
    UFUNCTION(BlueprintCallable)
    void SetScrollbarThickness(const FVector2D& NewScrollbarThickness);
    
    UFUNCTION(BlueprintCallable)
    void SetScrollBarPadding(const FMargin& NewScrollbarPadding);
    
    UFUNCTION(BlueprintCallable)
    void SetNavigationDestination(const EDescendantScroll2DDestination NewNavigationDestination);
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysShowScrollbar(bool NewAlwaysShowScrollbar);
    
    UFUNCTION(BlueprintCallable)
    void ScrollWidgetIntoView(UWidget* WidgetToFind, EDescendantScroll2DDestination ScrollDestination, FVector2D Padding);
    
    UFUNCTION(BlueprintCallable)
    void ScrollToStart();
    
    UFUNCTION(BlueprintCallable)
    void ScrollToNormalizedPosition(FVector2D NormalizedPosition, bool bAnimateScroll);
    
    UFUNCTION(BlueprintCallable)
    void ScrollToEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetViewOffsetFraction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetViewFraction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetScrollOffsetOfEnd() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetScrollOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetCurrentScrollPositionNormalized();
    
    UFUNCTION(BlueprintCallable)
    void EndInertialScrolling();
    
};

