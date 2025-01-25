#pragma once

#include <map>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BubbleSystemComponent.generated.h"

UENUM(BlueprintType)
enum class EBubbleType : uint8
{
	None = 0 UMETA(Hidden),
	Red,
	Green,
	Blue,
	End UMETA(Hidden)
};


USTRUCT(BlueprintType)
struct FBubbleMatching
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	EBubbleType BubbleType;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<EBubbleType> Matches;
};	



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerBubbleAssignedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreateBubbleEvent, EBubbleType, BubbleType, float, Position);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSuccessfulMatchEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailedMatchEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGJ25_API UBubbleSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBubbleSystemComponent();

	UFUNCTION(BlueprintCallable, Category = "GGJ25|Gameplay")
	void Collide(EBubbleType BubbleType);

	UPROPERTY(BlueprintAssignable, Category = "GGJ25|Gameplay")
	FOnPlayerBubbleAssignedEvent OnPlayerBubbleAssignedEvent;

	UPROPERTY(BlueprintAssignable, Category = "GGJ25|Gameplay")
	FOnCreateBubbleEvent OnCreateBubbleEvent;

	UPROPERTY(BlueprintAssignable, Category = "GGJ25|Gameplay")
	FOnSuccessfulMatchEvent OnSuccessfulMatchEvent;

	UPROPERTY(BlueprintAssignable, Category = "GGJ25|Gameplay")
	FOnFailedMatchEvent OnFailedMatchEvent;
	
	UPROPERTY(BlueprintReadOnly, Category = "GGJ25|Gameplay")
	EBubbleType CurrentPlayerBubbleType;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<FBubbleMatching> BubbleMatchEntries;

	UPROPERTY(EditDefaultsOnly)
	float MaxBubblesPerSecond;

	UPROPERTY(EditDefaultsOnly)
	float BubbleSpawnIntervalSeconds;

	UPROPERTY(EditDefaultsOnly)
	float BubbleSpawnAreaLength;

	UPROPERTY(EditDefaultsOnly)
	float BubbleRadius;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	std::map<EBubbleType, FBubbleMatching> BubbleMatching;
	FTimerHandle TimerHandle;

	void CreateBubbles();
	static EBubbleType GetRandomBubbleType();
	float GetRandomBubblePosition() const;
};
