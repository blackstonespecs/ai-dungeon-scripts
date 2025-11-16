// Generated from JSON Story Card
// Entity Type: Characters
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UTest_Hero.generated.h"

/**
 * A brave hero on a quest to save the world
 */
UCLASS(BlueprintType, Blueprintable)
class UTest_Hero : public UDataAsset
{
    GENERATED_BODY()

public:
    UTest_Hero();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    float health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    bool is_alive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> inventory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

};
