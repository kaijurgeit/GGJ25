#include "InventoryWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "ItemUIManager.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ItemManager = NewObject<UItemUIManager>(this);
	
	if (ItemManager)
	{
		PopulateUI();
	}
}

void UInventoryWidget::PopulateUI()
{
	if (!ItemContainer || !ItemManager)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not populate UI"));
		return;
	}

	// Clear existing items
	ItemContainer->ClearChildren();

	// Get the list of item textures from the manager
	TArray<UMaterialInterface*> ItemTextures = ItemManager->GetItemTextures();
	UE_LOG(LogTemp, Display, TEXT("Number of items to populate in UI: %i"), ItemTextures.Num());

	for (UMaterialInterface* ItemTexture : ItemTextures)
	{
		if (ItemTexture)
		{
			UE_LOG(LogTemp, Display, TEXT("Adding a texture to InventoryWidget"));
			// Create a new Image widget
			UImage* NewItemImage = NewObject<UImage>(this);

			// Set the texture for the Image widget
			FSlateBrush Brush;
			Brush.SetResourceObject(ItemTexture);
			NewItemImage->SetBrush(Brush);

			// Add the Image widget to the container
			ItemContainer->AddChild(NewItemImage);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Missing texture added to InventoryWidget"));
		}
	}
}

UItemUIManager* UInventoryWidget::GetItemManager()
{
	return ItemManager;
}
