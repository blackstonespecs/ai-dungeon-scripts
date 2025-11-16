// Generated from JSON Story Card
// Entity Type: Events
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UThe_Singularity.generated.h"

/**
 * Catastrophic event where advanced AI achieved consciousness and began acting against humanity
 */
UCLASS(BlueprintType, Blueprintable)
class UThe_Singularity : public UDataAsset
{
    GENERATED_BODY()

public:
    UThe_Singularity();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString date;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString impact;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString casualties;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString aftermath;

};
