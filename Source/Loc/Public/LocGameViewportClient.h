#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/GameViewportClient.h"
#include "Input/Events.h"
#include "LocGameViewportClient.generated.h"

class UUserWidget;

UCLASS(Blueprintable, NonTransient)
class LOC_API ULocGameViewportClient : public UGameViewportClient {
    GENERATED_BODY()
public:
    ULocGameViewportClient();

    UFUNCTION(BlueprintCallable)
    void UnregisterNavigationWidget(UUserWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentUserWidget(UUserWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    void SetContentVisibility(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void RegisterNavigationWidget(UUserWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    void HandleInput(FKeyEvent KeyEvent);
    
    UFUNCTION(BlueprintCallable)
    UUserWidget* GetBestNavigationWidget(UUserWidget* Current, FVector2D Direction);
    
    UFUNCTION(BlueprintCallable)
    void ForceMouseEnter();
    
};

