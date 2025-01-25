#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UHorizontalBox;
class UTexture2D;
class UItemUIManager;

UCLASS()
class GGJ25_API UInventoryWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Function to populate the UI with items
    void PopulateUI();

protected:
    // The container widget for dynamically added images
    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* ItemContainer;

    // Reference to the Item Manager
    UPROPERTY()
    UItemUIManager* ItemManager;
};

