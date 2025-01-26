#include "BubbleSystemComponent.h"
#include "Math/UnrealMathUtility.h"

UBubbleSystemComponent::UBubbleSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBubbleSystemComponent::Collide(EBubbleType BubbleType)
{
	UpdateMatchingPlayerBubbleTypes();
	if (BubbleMatching.at(CurrentPlayerBubbleType).Matches.Contains(BubbleType))
	{	
		OnSuccessfulMatchEvent.Broadcast();
	}
	else
	{
		OnFailedMatchEvent.Broadcast();
	}
	
	CurrentPlayerBubbleType = BubbleType;
	OnPlayerBubbleAssignedEvent.Broadcast();
}

void UBubbleSystemComponent::BeginPlay()
{
	Super::BeginPlay();
	for (auto& Entry : BubbleMatchEntries)
	{
		BubbleMatching.insert({Entry.BubbleType, Entry});
	}

	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, this, &UBubbleSystemComponent::CreateBubbles, BubbleSpawnIntervalSeconds, true, BubbleSpawnIntervalSeconds);

	// CurrentPlayerBubbleType = GetRandomBubbleType();
	UpdateMatchingPlayerBubbleTypes();
	OnPlayerBubbleAssignedEvent.Broadcast();
}

void UBubbleSystemComponent::CreateBubbles()
{
	int MaxBubblesToSpawn = MaxBubblesPerSecond / BubbleSpawnIntervalSeconds;
	int BubblesToSpawn = FMath::RandRange(1, MaxBubblesToSpawn);
	for (int i = 0; i < BubblesToSpawn; ++i)
	{
		OnCreateBubbleEvent.Broadcast(GetRandomBubbleType());
	}
}

void UBubbleSystemComponent::UpdateMatchingPlayerBubbleTypes()
{
	MatchingPlayerBubbleTypes = BubbleMatching.at(CurrentPlayerBubbleType).Matches;
}

EBubbleType UBubbleSystemComponent::GetRandomBubbleType()
{
	return static_cast<EBubbleType>(FMath::RandRange(static_cast<int8>(EBubbleType::None) + 1, static_cast<int8>(EBubbleType::End) - 1));
}

