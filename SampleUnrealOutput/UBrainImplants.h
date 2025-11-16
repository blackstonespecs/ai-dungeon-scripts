// Generated from JSON Story Card
// Entity Type: Technology
// Generated: 2025-11-16 03:01:08

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UNeural_Interface_Implants.generated.h"

/**
 * Experimental brain implants providing direct neural interface
 */
UCLASS(BlueprintType, Blueprintable)
class UNeural_Interface_Implants : public UDataAsset
{
    GENERATED_BODY()

public:
    UNeural_Interface_Implants();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> capabilities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    TArray<FString> risks;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString status;

};
