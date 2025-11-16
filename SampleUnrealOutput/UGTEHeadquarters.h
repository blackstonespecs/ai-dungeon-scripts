// Generated from JSON Story Card
// Entity Type: Locations
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UGTE_Headquarters.generated.h"

/**
 * Corporate hub for AI development and research
 */
UCLASS(BlueprintType, Blueprintable)
class UGTE_Headquarters : public UDataAsset
{
    GENERATED_BODY()

public:
    UGTE_Headquarters();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString status;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 floors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 security_level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> notable_areas;

};
