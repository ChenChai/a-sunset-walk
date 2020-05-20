// Copyright Chen Chai 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Sound/SoundCue.h" 
#include "MusicInstrumentPlayer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASUNSETWALK_API UMusicInstrumentPlayer : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMusicInstrumentPlayer();

	void StartPlayingSound();
	void StopPlayingSound();

	// Sets whether the instrument is always playing.
	// If set to true, the instrument will play and  
	// StopPlayingSound() will not do anything.
	void SetAlwaysPlaying(bool AlwaysPlaying);
	bool GetAlwaysPlaying() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	// Sound Cue to play when instrument starts playing
	UPROPERTY(EditAnywhere)
	USoundCue* MusicSoundCue;

	// Audio component which is currently playing
	UAudioComponent* CurrentlyPlayingAudioComponent = nullptr;
	
	// Whether the instrument is always playing. If set to true,
	// StopPlaying will not do anything.
	bool IsAlwaysPlaying = false;
};
