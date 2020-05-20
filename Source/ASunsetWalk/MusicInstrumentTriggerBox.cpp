// Copyright Chen Chai 2020


#include "MusicInstrumentTriggerBox.h"
#include "MusicInstrument.h"

AMusicInstrumentTriggerBox::AMusicInstrumentTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AMusicInstrumentTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMusicInstrumentTriggerBox::OnOverlapEnd);

}

void AMusicInstrumentTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}

void AMusicInstrumentTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) 
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap began!"))

	// If an instrument entered the box, we will "return" the instrument home.	
	if (OtherActor && (OtherActor != this)) {
		if (AMusicInstrument* MusicInstrument = dynamic_cast<AMusicInstrument*>(OtherActor)) {
			UE_LOG(LogTemp, Warning, TEXT("Was a music instrument!!"))

			MusicInstrument->ReturnInstrument();
		}
	}
}

void AMusicInstrumentTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Ended!"))
}