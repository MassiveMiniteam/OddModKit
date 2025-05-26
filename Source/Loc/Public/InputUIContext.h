#pragma once
#include "CoreMinimal.h"
#include "InputContext.h"
#include "InputUIContext.generated.h"

class UNavUserWidget;

UCLASS(Blueprintable)
class LOC_API UInputUIContext : public UInputContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNavUserWidget> NavUserWidget;
    
    UInputUIContext();

};

