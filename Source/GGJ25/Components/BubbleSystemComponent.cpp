#include "BubbleSystemComponent.h"
#include "Math/UnrealMathUtility.h"

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

	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(TimerHandle, this, &UBubbleSystemComponent::CreateBubbles, BubbleSpawnIntervalSeconds, true, BubbleSpawnIntervalSeconds);

	CurrentPlayerBubbleType = GetRandomBubbleType();
	OnPlayerBubbleAssignedEvent.Broadcast();
}

void UBubbleSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
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

EBubbleType UBubbleSystemComponent::GetRandomBubbleType()
{
	return static_cast<EBubbleType>(FMath::RandRange(static_cast<int8>(EBubbleType::None) + 1, static_cast<int8>(EBubbleType::End) - 1));
}

