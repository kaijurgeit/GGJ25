// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Pawns/BubblePawn.h"

void ABubblePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);	
	Subsystem->AddMappingContext(DefaultMappingContext, 0);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
}

void ABubblePlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	BubblePawn = Cast<ABubblePawn>(InPawn);
}
 
void ABubblePlayerController::Input_Move(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();
	
	BubblePawn->AddMovementInput(FVector::ForwardVector, MovementValue);
}
