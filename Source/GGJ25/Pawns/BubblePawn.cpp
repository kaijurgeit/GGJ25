// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblePawn.h"

#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
ABubblePawn::ABubblePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	RootComponent = SphereComponent;
	
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
}

// Called when the game starts or when spawned
void ABubblePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABubblePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABubblePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

