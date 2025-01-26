// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblePawn.h"

#include "Components/BubbleSystemComponent.h"
#include "Components/MaterialBillboardComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"


ABubblePawn::ABubblePawn()
{
	MaterialBillboard = CreateDefaultSubobject<UMaterialBillboardComponent>("MaterialBillboard");
	MaterialBillboard->SetupAttachment(GetRootComponent());

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

void ABubblePawn::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                        FVector NormalImpulse, const FHitResult& Hit)
{
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
	UBubbleSystemComponent* BubbleSystem = GameMode->GetComponentByClass<UBubbleSystemComponent>();

	if (BubbleSystem)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("%s"), *FString(__FUNCTION__)));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("%s"), *FString(__FUNCTION__)));
	}
}
