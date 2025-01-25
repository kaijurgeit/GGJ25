#include "InventoryWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "ItemUIManager.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//ItemManager = NewObject<UItemUIManager>(this);
	
	if (ItemManager)
	{
		PopulateUI();
	}
}

void UInventoryWidget::PopulateUI()
{
	if (!ItemContainer || !ItemManager)
	{
		return;
	}

	// Clear existing items
	ItemContainer->ClearChildren();

	// Get the list of item textures from the manager
	TArray<UTexture2D*> ItemTextures = ItemManager->GetItemTextures();

	for (UTexture2D* ItemTexture : ItemTextures)
	{
		if (ItemTexture)
		{
			// Create a new Image widget
			UImage* NewItemImage = NewObject<UImage>(this);

			// Set the texture for the Image widget
			FSlateBrush Brush;
			Brush.SetResourceObject(ItemTexture);
			NewItemImage->SetBrush(Brush);

			// Add the Image widget to the container
			ItemContainer->AddChild(NewItemImage);
		}
	}
}
