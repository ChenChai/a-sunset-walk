// Copyright Chen Chai 2020

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MusicInstrumentTriggerBox.generated.h"

/**
 * This class is a trigger box which acts as a "collection zone"
 * for music instruments the user collects.
 */
UCLASS()
class ASUNSETWALK_API AMusicInstrumentTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMusicInstrumentTriggerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UFUNCTION()
	virtual void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};
