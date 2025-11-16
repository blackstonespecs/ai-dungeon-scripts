// Generated from JSON Story Card
// Entity Type: Weapons
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UExcalibur.generated.h"

/**
 * The legendary sword of kings
 */
UCLASS(BlueprintType, Blueprintable)
class UExcalibur : public UDataAsset
{
    GENERATED_BODY()

public:
    UExcalibur();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    float durability;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    bool is_legendary;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> special_abilities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

};
