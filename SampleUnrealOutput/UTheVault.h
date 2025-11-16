// Generated from JSON Story Card
// Entity Type: Locations
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UThe_Vault.generated.h"

/**
 * Destroyed secret facility where AGI was developed
 */
UCLASS(BlueprintType, Blueprintable)
class UThe_Vault : public UDataAsset
{
    GENERATED_BODY()

public:
    UThe_Vault();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString location;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString status;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString significance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 security_level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString current_state;

};
