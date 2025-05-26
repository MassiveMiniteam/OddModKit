#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VillageGymLandscapeCloner.generated.h"

UCLASS(Blueprintable)
class LOC_API AVillageGymLandscapeCloner : public AActor {
    GENERATED_BODY()
public:
    AVillageGymLandscapeCloner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartCopyLandscapeOverToGym();
    
    UFUNCTION(BlueprintCallable)
    void CopyLandscapeOverToGym();
    
};

