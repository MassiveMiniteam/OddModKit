#pragma once
#include "CoreMinimal.h"
#include "CellToISM_Manager.h"
#include "Templates/SubclassOf.h"
#include "CellToISM_Manager_OverlayDrawer.generated.h"

class UComponentRegistrationSubsystem;

UCLASS(Blueprintable)
class LOC_API ACellToISM_Manager_OverlayDrawer : public ACellToISM_Manager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UComponentRegistrationSubsystem> SubsystemType;
    
public:
    ACellToISM_Manager_OverlayDrawer(const FObjectInitializer& ObjectInitializer);

};

