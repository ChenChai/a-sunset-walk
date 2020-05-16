// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicInstrumentPlayer.h"

// Sets default values for this component's properties
UMusicInstrumentPlayer::UMusicInstrumentPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UMusicInstrumentPlayer::StartPlayingSound()
{
}

void UMusicInstrumentPlayer::StopPlayingSound()
{
}

// Called when the game starts
void UMusicInstrumentPlayer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMusicInstrumentPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

