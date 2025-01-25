// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/Pawn.h"
#include "BubblePawn.generated.h"

struct FInputActionValue;
class USphereComponent;
class UFloatingPawnMovement;

UCLASS()
class GGJ25_API ABubblePawn : public ADefaultPawn
{
	GENERATED_BODY()
	
public:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override {};
};
