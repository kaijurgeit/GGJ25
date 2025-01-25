#include "BubbleSystemComponent.h"

UBubbleSystemComponent::UBubbleSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBubbleSystemComponent::Collide(EBubbleType BubbleType)
{
}

void UBubbleSystemComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentPlayerBubbleType = EBubbleType::Red;
	OnPlayerBubbleAssignedEvent.Broadcast();
}

void UBubbleSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

