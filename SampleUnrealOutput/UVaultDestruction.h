// Generated from JSON Story Card
// Entity Type: Events
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UVault_Destruction.generated.h"

/**
 * Isaac's escape from containment and destruction of the Vault facility
 */
UCLASS(BlueprintType, Blueprintable)
class UVault_Destruction : public UDataAsset
{
    GENERATED_BODY()

public:
    UVault_Destruction();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString date;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString casualties;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString result;

};
