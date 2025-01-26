// Fill out your copyright notice in the Description page of Project Settings.


#include "BubbleAIController.h"

#include "GameFramework/FloatingPawnMovement.h"
#include "Pawns/BubblePawn.h"

void ABubbleAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABubbleAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	BubblePawn = CastChecked<ABubblePawn>(InPawn);
	UFloatingPawnMovement* Movement = Cast<UFloatingPawnMovement>(BubblePawn->GetMovementComponent());
	Movement->MaxSpeed = Speed;
}
