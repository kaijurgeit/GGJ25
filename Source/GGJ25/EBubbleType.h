#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EBubbleType : uint8
{
	None = 0 UMETA(Hidden),
	Red,
	Green,
	Blue,
	End UMETA(Hidden)
};