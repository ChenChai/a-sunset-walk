// Copyright Chen Chai 2020


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "ASunsetWalkGameStateBase.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!OpenVolume) {
		UE_LOG(LogTemp, Error, TEXT("%s has no Open Volume selected!"), *GetOwner()->GetName())
	}
}

void UOpenDoor::OpenDoor()
{
	OnOpenRequest.Broadcast();
}

void UOpenDoor::CloseDoor()
{
	OnCloseRequest.Broadcast();
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll trigger volume every frame, open door if ActorThatOpens 
	// is in the trigger volume, open the door

	// TODO use event trigger rather than polling
	if (!OpenVolume) { return; }

	// Only open the door if the player has returned one or more instruments
	AASunsetWalkGameStateBase* GameState = GetWorld() ? GetWorld()->GetGameState<AASunsetWalkGameStateBase>() : nullptr;

	if (GameState && GameState->GetReturnedInstruments() > 0 && OpenVolume->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor();	
	} else {
		CloseDoor();
	}
}

