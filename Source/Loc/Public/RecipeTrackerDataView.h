#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Fixed64.h"
#include "ERecipeTrackType.h"
#include "RecipeTrackerDataView.generated.h"

class UItemConfig;

UCLASS(Blueprintable)
class LOC_API URecipeTrackerDataView : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed64 NumSnapShotsPerPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumSnapShots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemConfig* ItemConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> DataPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtremaMinY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtremaMaxY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtremaMinX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtremaMaxX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERecipeTrackType Type;
    
public:
    URecipeTrackerDataView();

    UFUNCTION(BlueprintCallable)
    void SetType(ERecipeTrackType TypeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetTimeFrameMin(int32 Minutes);
    
    UFUNCTION(BlueprintCallable)
    void SetTimeFrame(int32 InNumSnapshots);
    
    UFUNCTION(BlueprintCallable)
    void SetItemConfig(UItemConfig* ItemConfigIn);
    
    UFUNCTION(BlueprintCallable)
    void Refresh();
    
    UFUNCTION(BlueprintCallable)
    void Init(UItemConfig* ItemConfigIn, ERecipeTrackType TypeIn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERecipeTrackType GetType() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetNumDataPoints();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemConfig* GetItemConfig() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FVector2D> GetGraphPoints();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExtremaMinY() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExtremaMinX() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExtremaMaxY() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExtremaMaxX() const;
    
};

