#include "BubbleSystemComponent.h"

UBubbleSystemComponent::UBubbleSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBubbleSystemComponent::Collide(EBubbleType BubbleType)
{
	try
	{
		if (BubbleMatching.at(CurrentPlayerBubbleType).Matches.Contains(BubbleType))
			OnSuccessfulMatchEvent.Broadcast();
		else
			OnFailedMatchEvent.Broadcast();
	}
	catch (const std::out_of_range&)
	{	
		UE_LOG(LogTemp, Error, TEXT("Failed to find bubble type %i"), static_cast<int>(CurrentPlayerBubbleType));
		OnFailedMatchEvent.Broadcast();
	}
}

void UBubbleSystemComponent::BeginPlay()
{
	Super::BeginPlay();
	for (auto& Entry : BubbleMatchEntries)
	{
		BubbleMatching.insert({Entry.BubbleType, Entry});
	}

	CurrentPlayerBubbleType = static_cast<EBubbleType>(FMath::RandRange(static_cast<int8>(EBubbleType::None) + 1, static_cast<int8>(EBubbleType::End) - 1));
	OnPlayerBubbleAssignedEvent.Broadcast();
}

void UBubbleSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

