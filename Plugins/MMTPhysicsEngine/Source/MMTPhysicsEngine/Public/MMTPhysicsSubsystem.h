#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MMTPhysicsSubsystem.generated.h"

class UMMTPhysicsComponent;

UCLASS(Blueprintable)
class MMTPHYSICSENGINE_API UMMTPhysicsSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMMTPhysicsComponent*> PhysicsComponents;
    
public:
    UMMTPhysicsSubsystem();

};

