// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblePawn.h"

#include "Components/BubbleSystemComponent.h"
#include "Components/MaterialBillboardComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"


ABubblePawn::ABubblePawn()
{
	MaterialBillboard = CreateDefaultSubobject<UMaterialBillboardComponent>("MaterialBillboard");
	MaterialBillboard->SetupAttachment(GetRootComponent());

}

void ABubblePawn::BeginPlay()
{
	Super::BeginPlay();
	
	GetCollisionComponent()->OnComponentHit.AddDynamic(this, &ThisClass::OnHit);
}

void ABubblePawn::SetIconMaterial(UMaterial* Material)
{
	FMaterialSpriteElement SpriteElement;
	SpriteElement.Material = Material;
	TArray<FMaterialSpriteElement> SpriteElements;
	SpriteElements.Add(SpriteElement);
	MaterialBillboard->SetElements(SpriteElements);
}

UFloatingPawnMovement* ABubblePawn::GetFloatingMovement()
{
	return Cast<UFloatingPawnMovement>(MovementComponent);
}

void ABubblePawn::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                        FVector NormalImpulse, const FHitResult& Hit)
{
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
	UBubbleSystemComponent* BubbleSystem = GameMode->GetComponentByClass<UBubbleSystemComponent>();
	ABubblePawn* OtherBubble = Cast<ABubblePawn>(OtherActor);

	if (IsPlayerControlled() && BubbleSystem && OtherBubble)
	{
		if (BubbleSystem)
		{
			BubbleSystem->Collide(OtherBubble->BubbleType);
			OtherBubble->Destroy();
		}
	}
}
