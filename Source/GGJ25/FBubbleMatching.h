#pragma once

#include "CoreMinimal.h"
#include "EBubbleType.h"
#include "FBubbleMatching.generated.h"

USTRUCT(BlueprintType)
struct FBubbleMatching
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	EBubbleType BubbleType;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<EBubbleType> Matches;
};	
