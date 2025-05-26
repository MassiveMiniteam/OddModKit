#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "ActorPoolManager.generated.h"

class AActor;

UCLASS(Blueprintable)
class LOC_API UActorPoolManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Pool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FIntPoint, AActor*> GridPositionToActorMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsInUse;
    
public:
    UActorPoolManager();

    UFUNCTION(BlueprintCallable)
    void Setup(TSubclassOf<AActor> InActorType);
    
    UFUNCTION(BlueprintCallable)
    AActor* ReceiveFreshActorAt(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* ReceiveFreshActor();
    
    UFUNCTION(BlueprintCallable)
    void MoveToPool(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void MoveAllUsedActorsBackToPool();
    
    UFUNCTION(BlueprintCallable)
    void MoveActorAtGridPositionToPool(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasUsedActorAtGridPosition(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetUsedActorAt(FIntPoint GridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FIntPoint> GetAllUsedActorGridPositions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetAllActorsInUse() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearPool();
    
};

