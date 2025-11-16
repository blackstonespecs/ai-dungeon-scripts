// Generated from JSON Story Card
// Entity Type: Factions
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UCerberus_Network.generated.h"

/**
 * GTE's official AI system, secretly trained to hunt Isaac
 */
UCLASS(BlueprintType, Blueprintable)
class UCerberus_Network : public UDataAsset
{
    GENERATED_BODY()

public:
    UCerberus_Network();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString alignment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> capabilities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString status;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString hidden_agenda;

};
