#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "GlossaryGameplayDataPlayer.generated.h"

class UGlossaryGameplayData;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlossaryGameplayDataPlayer : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UGlossaryGameplayDataPlayer(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShowGameplayData(UGlossaryGameplayData* GameplayData);
    
    UFUNCTION(BlueprintCallable)
    void OnDataUnlocked(UUnlockableDataAsset* UnlockedData);
    
};

