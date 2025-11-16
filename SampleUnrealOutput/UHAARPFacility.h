// Generated from JSON Story Card
// Entity Type: Locations
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UHAARP_Facility.generated.h"

/**
 * Alaska facility capable of weather manipulation and EMP attacks
 */
UCLASS(BlueprintType, Blueprintable)
class UHAARP_Facility : public UDataAsset
{
    GENERATED_BODY()

public:
    UHAARP_Facility();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString status;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString controlled_by;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> capabilities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 threat_level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString defenses;

};
