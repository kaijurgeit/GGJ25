#include "DataAssets/BubbleMaterialDataAsset.h"

const UMaterial* UBubbleMaterialDataAsset::GetMaterial(EBubbleType BubbleType) const
{
	for (auto& Item : BubbleMaterials)
	{
		if (Item.BubbleType == BubbleType)
			return Item.Material;
	}
		
	return nullptr;
}

const UTexture2D* UBubbleMaterialDataAsset::GetTexture(EBubbleType BubbleType) const
{
	for (auto& Item : BubbleMaterials)
	{
		if (Item.BubbleType == BubbleType)
			return Item.Texture;
	}
		
	return nullptr;
}
