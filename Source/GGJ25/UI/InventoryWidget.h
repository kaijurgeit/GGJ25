#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemUIManager.h"
#include "InventoryWidget.generated.h"

class UHorizontalBox;
class UTexture2D;

UCLASS()
class GGJ25_API UInventoryWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Function to populate the UI with items
    UFUNCTION(BlueprintCallable)
    void PopulateUI();

    UFUNCTION(BlueprintCallable)
    UItemUIManager* GetItemManager();

protected:
    // The container widget for dynamically added images
    UPROPERTY(EditAnywhere, meta = (BindWidget))
    UHorizontalBox* ItemContainer;

    // Reference to the Item Manager
    UPROPERTY(EditAnywhere)
    UItemUIManager* ItemManager;
};

