// Copyright Chen Chai 2020


#include "ASunsetWalkGameStateBase.h"

void AASunsetWalkGameStateBase::ReturnInstrument()
{
	ReturnedInstruments++;

	UE_LOG(LogTemp, Warning, TEXT("Returned an instrument! ReturnedInstruments = %d"), ReturnedInstruments);
}

int AASunsetWalkGameStateBase::GetReturnedInstruments()
{
	return ReturnedInstruments;
}
