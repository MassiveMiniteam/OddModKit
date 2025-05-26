#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UILocSubsystem.generated.h"

class UButtonPromptBarItemSet;
class UButtonPromptBarWidget;

UCLASS(Blueprintable)
class LOC_API UUILocSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UButtonPromptBarWidget> MainButtonPromptBar;
    
    UUILocSubsystem();

    UFUNCTION(BlueprintCallable)
    void PushButtonPromptSet(UButtonPromptBarItemSet* ButtonPrompts);
    
    UFUNCTION(BlueprintCallable)
    void PopButtonPromptSet(UButtonPromptBarItemSet* ButtonPrompts);
    
};

