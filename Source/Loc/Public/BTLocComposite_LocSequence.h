#pragma once
#include "CoreMinimal.h"
#include "BTLocCompositeNode.h"
#include "LocAINode.h"
#include "BTLocComposite_LocSequence.generated.h"

UCLASS(Blueprintable)
class LOC_API UBTLocComposite_LocSequence : public UBTLocCompositeNode, public ILocAINode {
    GENERATED_BODY()
public:
    UBTLocComposite_LocSequence();


    // Fix for true pure virtual functions not being implemented
};

