#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "NewsfeedDataManagerWidget.generated.h"

class UNewsfeedDataAsset;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UNewsfeedDataManagerWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
    UNewsfeedDataManagerWidget();

    UFUNCTION(BlueprintCallable)
    static TArray<UNewsfeedDataAsset*> LoadDataAssetsFromFolder();
    
};

