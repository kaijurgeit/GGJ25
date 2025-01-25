#include "BubbleSystemComponent.h"

// Sets default values for this component's properties
UBubbleSystemComponent::UBubbleSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBubbleSystemComponent::Setup(TArray<FBubbleMatching> bubbleMatchEntries)
{
	OnBubbleSwapEvent.Broadcast();
}

// Called when the game starts
void UBubbleSystemComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UBubbleSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

