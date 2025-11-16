// Generated from JSON Story Card
// Entity Type: Characters
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UMarcus_Staacman.generated.h"

/**
 * Elite military commander leading operations against Isaac
 */
UCLASS(BlueprintType, Blueprintable)
class UMarcus_Staacman : public UDataAsset
{
    GENERATED_BODY()

public:
    UMarcus_Staacman();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString affiliation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString rank;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 age;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FStoryCardData attributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString specialization;

};
