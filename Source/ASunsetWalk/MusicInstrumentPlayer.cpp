// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicInstrumentPlayer.h"
#include "Components/AudioComponent.h" 
#include "Kismet/GameplayStatics.h" 

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
	UE_LOG(LogTemp, Warning, TEXT("StartPlayingSound called!"));
	CurrentlyPlayingAudioComponent = UGameplayStatics::SpawnSoundAttached(
		MusicSoundCue,
		GetOwner()->GetDefaultAttachComponent(),
		NAME_None,
		FVector(),
		EAttachLocation::KeepRelativeOffset
	);
}

void UMusicInstrumentPlayer::StopPlayingSound()
{
	UE_LOG(LogTemp, Warning, TEXT("StopPlayingSound called!"));

	if (CurrentlyPlayingAudioComponent) {
		CurrentlyPlayingAudioComponent->FadeOut(1.0f, 0.0f);
		CurrentlyPlayingAudioComponent->DestroyComponent();
		CurrentlyPlayingAudioComponent = nullptr;
	}
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

