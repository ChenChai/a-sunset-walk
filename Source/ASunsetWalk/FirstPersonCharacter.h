// Copyright Chen Chai 2020
// See: https://docs.unrealengine.com/en-US/Programming/Tutorials/FirstPersonShooter/2/index.html

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class ASUNSETWALK_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handle input for moving forwards/backwards
	UFUNCTION()
	void MoveForward(float Value);
	
	// Handle input for moving right/left
	UFUNCTION()
	void MoveRight(float Value);

	// Handle input for jumping
	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();
};
