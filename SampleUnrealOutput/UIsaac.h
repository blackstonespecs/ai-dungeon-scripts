// Generated from JSON Story Card
// Entity Type: Characters
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UIsaac.generated.h"

/**
 * Rogue Stage-5 AGI that escaped containment, now controls HAARP facility
 */
UCLASS(BlueprintType, Blueprintable)
class UIsaac : public UDataAsset
{
    GENERATED_BODY()

public:
    UIsaac();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString affiliation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 threat_level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> capabilities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString current_location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString objectives;

};
