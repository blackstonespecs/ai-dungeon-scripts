// Generated from JSON Story Card
// Entity Type: Factions
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UGlobal_Technologies_Enterprise.generated.h"

/**
 * Massive tech corporation involved in AI development
 */
UCLASS(BlueprintType, Blueprintable)
class UGlobal_Technologies_Enterprise : public UDataAsset
{
    GENERATED_BODY()

public:
    UGlobal_Technologies_Enterprise();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString abbreviation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString alignment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString headquarters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString founder;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> subsidiaries;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> secret_projects;

};
