// Copyright Chen Chai 2020


#include "MusicInstrument.h"

// Sets default values
AMusicInstrument::AMusicInstrument()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMusicInstrument::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMusicInstrument::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Override FellOutOfWorld to place the instrument at the respawn location instead of destroying it.
void AMusicInstrument::FellOutOfWorld(const UDamageType& dmgType) {
	UE_LOG(LogTemp, Warning, TEXT("fell out of world!"))

	// Teleport actor to respawn location and reset the physics so it's unmoving
	SetActorLocation(RespawnLocation, false, (FHitResult *) nullptr, ETeleportType::ResetPhysics);
}
