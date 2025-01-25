#include "ItemUIManager.h"
#include "Engine/Texture2D.h"


UItemUIManager::UItemUIManager()
{
	ItemTextures = TArray<UTexture2D*>();
}

TArray<UTexture2D*> UItemUIManager::GetItemTextures() const
{
	return ItemTextures;
}

void UItemUIManager::AddItemTexture(UTexture2D* NewTexture)
{
	if (NewTexture)
	{
		ItemTextures.Add(NewTexture);
	}
}

void UItemUIManager::RemoveItemTexture(UTexture2D* TextureToRemove)
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

