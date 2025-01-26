// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/Pawn.h"
#include "BubblePawn.generated.h"

class UMaterialBillboardComponent;
struct FInputActionValue;
class USphereComponent;
class UFloatingPawnMovement;
enum class EBubbleType : uint8;


UCLASS()
class GGJ25_API ABubblePawn : public ADefaultPawn
{
	GENERATED_BODY()
	
public:
	ABubblePawn();
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override {};

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void SetIconMaterial(UMaterial* Material);

	UFUNCTION(BlueprintCallable)
	UFloatingPawnMovement* GetFloatingMovement();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GGJ25|Pawn")
	EBubbleType BubbleType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GGJ25|Pawn")
	TObjectPtr<UMaterialBillboardComponent> MaterialBillboard;

private:
	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);
};
