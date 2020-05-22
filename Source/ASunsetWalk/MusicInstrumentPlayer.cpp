// Copyright Chen Chai 2020


#include "MusicInstrumentPlayer.h"
#include "Components/AudioComponent.h" 
#include "Kismet/GameplayStatics.h" 
#include <math.h>

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
	if (IsAlwaysPlaying) { return; }
	if (!MusicSoundCue) { return; }

	if (CurrentlyPlayingAudioComponent) {
		CurrentlyPlayingAudioComponent->DestroyComponent();
		CurrentlyPlayingAudioComponent = nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("StartPlayingSound called!"));

	UE_LOG(LogTemp, Warning, TEXT("Component Location: %s"), *SceneComponentToAttachTo->GetComponentLocation().ToString())
	CurrentlyPlayingAudioComponent = UGameplayStatics::SpawnSoundAttached(
		MusicSoundCue,
		SceneComponentToAttachTo,
		NAME_None,
		FVector(),
		EAttachLocation::KeepRelativeOffset,
		true,
		1.0f,
		1.0f,
		0.0f,
		AttenuationSettings,
		(USoundConcurrency*) nullptr,
		false
	);

	CurrentlyPlayingAudioComponent->FadeIn(
		2.0f, 
		1.0f, 
		// Start at the location of the track which all audio tracks are playing at
		fmod(GetWorld()->GetTimeSeconds(), MusicSoundCue->GetDuration())
	);
}

void UMusicInstrumentPlayer::StopPlayingSound()
{
	UE_LOG(LogTemp, Warning, TEXT("StopPlayingSound called!"));

	// Don't stop playing if the player is supposed to always play
	if (IsAlwaysPlaying) { return; }

	if (CurrentlyPlayingAudioComponent) {
		CurrentlyPlayingAudioComponent->FadeOut(2.0f, 0.0f);
	}
}

void UMusicInstrumentPlayer::SetAlwaysPlaying(bool AlwaysPlaying)
{
	if (AlwaysPlaying) {
		StopPlayingSound();
		StartPlayingSound();
	}
	IsAlwaysPlaying = AlwaysPlaying;
}

bool UMusicInstrumentPlayer::GetAlwaysPlaying() const
{
	return IsAlwaysPlaying;
}

// Called when the game starts
void UMusicInstrumentPlayer::BeginPlay()
{
	Super::BeginPlay();
	SceneComponentToAttachTo = GetOwner()->FindComponentByClass<USceneComponent>();
	if (!SceneComponentToAttachTo) {
		UE_LOG(LogTemp, Error, TEXT("%s has no USceneComponent to attach music to for MusicInstrumentPlayer!"), *GetOwner()->GetName())
	}
}

// Called every frame
void UMusicInstrumentPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

