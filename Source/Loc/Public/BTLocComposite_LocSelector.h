#pragma once
#include "CoreMinimal.h"
#include "BTLocCompositeNode.h"
#include "LocAINode.h"
#include "BTLocComposite_LocSelector.generated.h"

UCLASS(Blueprintable)
class LOC_API UBTLocComposite_LocSelector : public UBTLocCompositeNode, public ILocAINode {
    GENERATED_BODY()
public:
    UBTLocComposite_LocSelector();


    // Fix for true pure virtual functions not being implemented
};

