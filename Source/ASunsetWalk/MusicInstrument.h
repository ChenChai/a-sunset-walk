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

private:
	// Where the instrument respawns after falling out of the world
	UPROPERTY(EditAnywhere)
	FVector RespawnLocation = FVector();
};
