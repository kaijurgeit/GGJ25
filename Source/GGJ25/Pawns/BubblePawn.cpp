// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblePawn.h"

#include "InputActionValue.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
ABubblePawn::ABubblePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	RootComponent = SphereComponent;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>("Floating Movement");
}

UFloatingPawnMovement* ABubblePawn::GetFloatingMovement()
{
	return FloatingMovement;
}
