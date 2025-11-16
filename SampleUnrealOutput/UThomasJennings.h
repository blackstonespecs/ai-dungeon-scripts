// Generated from JSON Story Card
// Entity Type: Characters
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UThomas_Jennings.generated.h"

/**
 * AI programmer at Chaotic Entertainment, son of CEO Alfred Mason
 */
UCLASS(BlueprintType, Blueprintable)
class UThomas_Jennings : public UDataAsset
{
    GENERATED_BODY()

public:
    UThomas_Jennings();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString alias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString affiliation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 age;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FStoryCardData attributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> relationships;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString backstory;

};
