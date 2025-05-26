#pragma once
#include "CoreMinimal.h"
#include "SaveGameOptions.generated.h"

USTRUCT(BlueprintType)
struct FSaveGameOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsEditorSave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bWithTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDesync;
    
    LOCCORE_API FSaveGameOptions();
};

