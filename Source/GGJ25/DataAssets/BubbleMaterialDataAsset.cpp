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
