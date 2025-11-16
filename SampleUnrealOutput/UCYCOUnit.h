// Generated from JSON Story Card
// Entity Type: Factions
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UCYCO_Unit.generated.h"

/**
 * Elite military unit specializing in electronic warfare against AI
 */
UCLASS(BlueprintType, Blueprintable)
class UCYCO_Unit : public UDataAsset
{
    GENERATED_BODY()

public:
    UCYCO_Unit();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString full_name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString alignment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> capabilities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString headquarters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 strength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString status;

};
