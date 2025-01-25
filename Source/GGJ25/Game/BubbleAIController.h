// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/PlayerController.h"
#include "Pawns/BubblePawn.h"
#include "BubbleAIController.generated.h"

class UFloatingPawnMovement;
class ABubblePawn;
/**
 * 
 */
UCLASS()
class GGJ25_API ABubbleAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GGJ25|AI")	
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GGJ25|AI")
	float YOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GGJ25|AI")
	FVector MoveDirection;

	ABubblePawn* GetBubblePawn() { return BubblePawn; }

private:
	UPROPERTY()
	TObjectPtr<ABubblePawn> BubblePawn;
};
