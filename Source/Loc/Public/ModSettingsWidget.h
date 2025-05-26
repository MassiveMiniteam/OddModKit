#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "ModSettingsWidget.generated.h"

class UModInstance;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UModSettingsWidget : public UNavUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModInstance* ModInstance;
    
    UModSettingsWidget();

};

