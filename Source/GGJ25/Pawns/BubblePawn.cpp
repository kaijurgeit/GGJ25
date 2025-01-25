// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblePawn.h"

#include "Components/MaterialBillboardComponent.h"
#include "Components/StaticMeshComponent.h"


ABubblePawn::ABubblePawn()
{
	MaterialBillboard = CreateDefaultSubobject<UMaterialBillboardComponent>("MaterialBillboard");
	MaterialBillboard->SetupAttachment(GetRootComponent());
}
