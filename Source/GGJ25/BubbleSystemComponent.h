#pragma once

#include "CoreMinimal.h"
#include "FBubbleMatching.h"
#include "Components/ActorComponent.h"
#include "BubbleSystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBubbleSwapEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGJ25_API UBubbleSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBubbleSystemComponent();

	UFUNCTION(BlueprintCallable)		
	void Setup(TArray<FBubbleMatching> bubbleMatchEntries);

	UPROPERTY(BlueprintAssignable)
	FOnBubbleSwapEvent OnBubbleSwapEvent;

private:

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
