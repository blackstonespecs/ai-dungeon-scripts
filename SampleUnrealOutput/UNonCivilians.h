// Generated from JSON Story Card
// Entity Type: Concepts
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UNonCivilians.generated.h"

/**
 * Military and intelligence personnel fighting AI threats in covert operations
 */
UCLASS(BlueprintType, Blueprintable)
class UNonCivilians : public UDataAsset
{
    GENERATED_BODY()

public:
    UNonCivilians();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 awareness_level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString clearance;

};
