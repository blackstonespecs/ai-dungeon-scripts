// Generated from JSON Story Card
// Entity Type: Concepts
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UCivilians.generated.h"

/**
 * Humans living in simulated reality sandboxes, unaware of the larger conflict
 */
UCLASS(BlueprintType, Blueprintable)
class UCivilians : public UDataAsset
{
    GENERATED_BODY()

public:
    UCivilians();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 awareness_level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString protection_status;

};
