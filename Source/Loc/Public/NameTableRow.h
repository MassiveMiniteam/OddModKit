#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "NameTableRow.generated.h"

USTRUCT(BlueprintType)
struct FNameTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    LOC_API FNameTableRow();
};

