#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/BubbleSystemComponent.h"
#include "BubbleMaterialDataAsset.generated.h"

USTRUCT()
struct FBubbleMaterial
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	EBubbleType BubbleType;

	UPROPERTY(EditDefaultsOnly)
	UMaterial* Material;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Texture;
};

UCLASS()
class GGJ25_API UBubbleMaterialDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<FBubbleMaterial> BubbleMaterials;

	UFUNCTION(BlueprintCallable)
	const UMaterial* GetMaterial(EBubbleType BubbleType) const;

	UFUNCTION(BlueprintCallable)
	const UTexture2D* GetTexture(EBubbleType BubbleType) const;
};
