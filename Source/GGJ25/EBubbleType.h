#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EBubbleType : uint8
{
	None = 0,
	Red = 0b1,
	Green = 0b10,
	Blue = 0b100
};