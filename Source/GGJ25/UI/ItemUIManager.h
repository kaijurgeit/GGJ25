
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemUIManager.generated.h"

class UTexture2D;

UCLASS()
class GGJ25_API UItemUIManager : public UObject
{
	GENERATED_BODY()

public:
	UItemUIManager();

	// Returns the list of item textures
	UFUNCTION(BlueprintCallable, Category = "Item UI")
	TArray<UMaterialInterface*> GetItemTextures() const;

	// Adds a new texture to the list
	UFUNCTION(BlueprintCallable, Category = "Item UI")
	void AddItemTexture(UMaterialInterface* NewTexture);

	// Removes a texture from the list
	UFUNCTION(BlueprintCallable, Category = "Item UI")
	void RemoveItemTexture(UMaterialInterface* TextureToRemove);

	// Clears all textures from the list
	UFUNCTION(BlueprintCallable, Category = "Item UI")
	void ClearItemTextures();

private:
	//UPROPERTY()
	TArray<UMaterialInterface*> ItemTextures;
};

