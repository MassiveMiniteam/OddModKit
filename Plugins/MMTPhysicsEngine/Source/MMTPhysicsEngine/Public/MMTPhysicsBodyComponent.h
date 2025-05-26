#pragma once
#include "CoreMinimal.h"
#include "Fixed64.h"
#include "Fixed64Vector.h"
#include "MMTPhysicsComponent.h"
#include "MMTPhysicsBodyComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MMTPHYSICSENGINE_API UMMTPhysicsBodyComponent : public UMMTPhysicsComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64Vector ForceThisFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64Vector Velocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64Vector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 Mass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 Friction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 Radius;
    
public:
    UMMTPhysicsBodyComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64Vector GetLocation() const;
    
    UFUNCTION(BlueprintCallable)
    void DEBUG_AddForceY();
    
    UFUNCTION(BlueprintCallable)
    void DEBUG_AddForceX();
    
    UFUNCTION(BlueprintCallable)
    void AddForce(const FFixed64Vector& Force);
    
};

