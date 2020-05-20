// Copyright Chen Chai 2020


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

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
	if (!OpenVolume) { return; }
	if (OpenVolume->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor();	
	} else {
		CloseDoor();
	}
}

