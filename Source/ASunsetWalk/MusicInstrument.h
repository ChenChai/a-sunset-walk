// Copyright Chen Chai 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MusicInstrument.generated.h"

UCLASS()
class ASUNSETWALK_API AMusicInstrument : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicInstrument();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void FellOutOfWorld(const UDamageType& dmgType) override;

	// Called when instrument is returned home. Changes actor 
	// to static and moves it to its final location.
	virtual void ReturnInstrument();

private:
	// Where the instrument respawns after falling out of the world
	UPROPERTY(EditAnywhere)
	FVector RespawnLocation = FVector();

	// Final location of instrument once it has been returned
	UPROPERTY(EditAnywhere)
	FVector FinalLocation = FVector();

	// Whether the instrument has been returned to its final location.
	bool IsReturned = false;
};
