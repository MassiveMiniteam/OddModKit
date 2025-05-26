#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GridObjectCopyData.h"
#include "PasteMarker.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPasteMarker : public UUserWidget {
    GENERATED_BODY()
public:
    UPasteMarker();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupMarker(const FGridObjectCopyData& CopyData);
    
};

