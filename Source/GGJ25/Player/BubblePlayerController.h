// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BubblePlayerController.generated.h"

class ABubblePawn;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class GGJ25_API ABubblePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GGJ25|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GGJ25|Input")
	TObjectPtr<UInputAction> MoveAction;

private:
	TObjectPtr<ABubblePawn> BubblePawn;

	void Input_Move(const FInputActionValue& Value);
};
