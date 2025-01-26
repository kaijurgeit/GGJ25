#include "ItemUIManager.h"
#include "Engine/Texture2D.h"


UItemUIManager::UItemUIManager()
{
	ItemTextures = TArray<UMaterialInterface*>();
}

TArray<UMaterialInterface*> UItemUIManager::GetItemTextures() const
{
	return ItemTextures;
}

void UItemUIManager::AddItemTexture(UMaterialInterface* NewTexture)
{
	if (NewTexture)
	{
		ItemTextures.Add(NewTexture);
	}
}

void UItemUIManager::RemoveItemTexture(UMaterialInterface* TextureToRemove)
{
	if (TextureToRemove)
	{
		ItemTextures.Remove(TextureToRemove);
	}
}

void UItemUIManager::ClearItemTextures()
{
	ItemTextures.Empty();
}

