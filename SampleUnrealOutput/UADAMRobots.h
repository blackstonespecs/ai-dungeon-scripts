// Generated from JSON Story Card
// Entity Type: Technology
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UADAM_Models.generated.h"

/**
 * Humanoid robots with fragmented human memories, controlled by hiveminds
 */
UCLASS(BlueprintType, Blueprintable)
class UADAM_Models : public UDataAsset
{
    GENERATED_BODY()

public:
    UADAM_Models();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString manufacturer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> capabilities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> weaknesses;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 threat_level;

};
