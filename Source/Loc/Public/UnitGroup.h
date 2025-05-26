#pragma once
#include "CoreMinimal.h"
#include "SerializedSimulationObject.h"
#include "UnitGroupWithMemberDelegateDelegate.h"
#include "UnitGroup.generated.h"

class UUnitGroupMemberSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UUnitGroup : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUnitGroupWithMemberDelegate OnMemberAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUnitGroupWithMemberDelegate OnMemberRemoved;
    
private:
    UPROPERTY(EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UUnitGroupMemberSimulationComponent>> Members;
    
public:
    UUnitGroup();

};

