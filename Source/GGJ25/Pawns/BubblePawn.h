// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BubblePawn.generated.h"

struct FInputActionValue;
class USphereComponent;
class UFloatingPawnMovement;

UCLASS()
class GGJ25_API ABubblePawn : public APawn
{
	GENERATED_BODY()

public:
	ABubblePawn();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GGJ25|Movement")
	TObjectPtr<USphereComponent> SphereComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GGJ25|Movement")
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GGJ25|Movement")
	TObjectPtr<UFloatingPawnMovement> Movement;
};
