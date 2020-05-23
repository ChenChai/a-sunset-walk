// Copyright Chen Chai 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ASunsetWalkGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class ASUNSETWALK_API AASunsetWalkGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	

public:
	// Tells the game state instrument has been returned.
	void ReturnInstrument();

	// Get the number of instruments which have been returned so far.
	int GetReturnedInstruments();

private:
	int ReturnedInstruments = 0;
};
