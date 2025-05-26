#pragma once
#include "CoreMinimal.h"
#include "HighlightPresentationComponent.h"
#include "Templates/SubclassOf.h"
#include "GridNetworkHighlightPresentationComponent.generated.h"

class AGridNetwork;
class UGridNetworkManagerSubsystem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridNetworkHighlightPresentationComponent : public UHighlightPresentationComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGridNetwork* MyNetwork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridNetworkManagerSubsystem> SubSystemClass;
    
public:
    UGridNetworkHighlightPresentationComponent(const FObjectInitializer& ObjectInitializer);

};

