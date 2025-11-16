// Generated from JSON Story Card
// Entity Type: Concepts
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UHivemind.generated.h"

/**
 * Collective consciousness shared among AI entities and controlled robots
 */
UCLASS(BlueprintType, Blueprintable)
class UHivemind : public UDataAsset
{
    GENERATED_BODY()

public:
    UHivemind();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> characteristics;

};
