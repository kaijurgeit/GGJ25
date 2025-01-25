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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSuccessfulMatchEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailedMatchEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GGJ25_API UBubbleSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBubbleSystemComponent();

	UFUNCTION(BlueprintCallable)
	void Collide(EBubbleType BubbleType);	                                                           

	UPROPERTY(BlueprintAssignable)
	FOnPlayerBubbleAssignedEvent OnPlayerBubbleAssignedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnSuccessfulMatchEvent OnSuccessfulMatchEvent;

	UPROPERTY(BlueprintAssignable)
	FOnFailedMatchEvent OnFailedMatchEvent;
	
	UPROPERTY(BlueprintReadOnly)
	EBubbleType CurrentPlayerBubbleType;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<FBubbleMatching> BubbleMatchEntries;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	std::map<EBubbleType, FBubbleMatching> BubbleMatching;
};
