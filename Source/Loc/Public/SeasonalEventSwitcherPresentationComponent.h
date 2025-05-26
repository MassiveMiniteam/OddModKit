#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "SeasonalEventSwitcherPresentationComponent.generated.h"

class USeasonalEventData;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USeasonalEventSwitcherPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<USeasonalEventData>> SeasonalEventData;
    
    USeasonalEventSwitcherPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

