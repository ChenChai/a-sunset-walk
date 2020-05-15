// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h" 
#include "Components/PrimitiveComponent.h" 
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandleComponent();
	SetupInputComponent();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandle->GetGrabbedComponent()) {
		FVector PlayerViewPointLocation = FVector();
		FRotator PlayerViewPointRotator = FRotator();

		// Get player viewpoint
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			PlayerViewPointLocation,
			PlayerViewPointRotator
		);

		FVector LineTraceEnd = PlayerViewPointLocation + (PlayerViewPointRotator.Vector() * Reach);

		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
}

void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed!"));

	// Ray-cast in vector player is looking in and find hit actors with physics actor set
	FHitResult HitResult = GetFirstPhysicsBodyInReach();

	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();

	AActor* ActorHit = HitResult.GetActor();

	if (ActorHit) {
		// If we hit something, attach physics handle
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true // allow rotation
		);
	}
}

void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Grab Released!"));
	PhysicsHandle->ReleaseComponent();
}

// Find attached physics handle component
void UGrabber::FindPhysicsHandleComponent()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle) {
		// Physics handle component found
	}
	else {
		// Physics handle not found!
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle component not found on %s with grabber component!"), *GetOwner()->GetName())
	}
}

void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) {
		// Input component found!
		// Bind inputs to functions
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		// Input component not found!
		UE_LOG(LogTemp, Error, TEXT("InputComponent component not found on %s with grabber component!"), *GetOwner()->GetName())
	}
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	// Start trace from player view point and trace until end of reach.
	FVector LineTraceStart = GetPlayerViewPointLocation();
	FVector LineTraceEnd = GetPlayerReachEndLocation();

	DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor(255, 0, 0), false, 0, 0, 4.0f);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		Hit, // Out parameter
		LineTraceStart,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), // Only look at physics actors
		FCollisionQueryParams(
			FName(""),
			false,     // Use simple collision
			GetOwner() // Ignore hitting our own pawn
		)
	);
	UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *Hit.GetActor()->GetFullName())

	return Hit;
}

const FVector UGrabber::GetPlayerViewPointLocation()
{
	FVector PlayerViewPointLocation = FVector();
	FRotator PlayerViewPointRotator = FRotator();

	// Get player viewpoint
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		PlayerViewPointLocation,
		PlayerViewPointRotator
	);
	return PlayerViewPointLocation;
}

const FVector UGrabber::GetPlayerReachEndLocation()
{
	FVector PlayerViewPointLocation = FVector();
	FRotator PlayerViewPointRotator = FRotator();

	// Get player viewpoint
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		PlayerViewPointLocation,
		PlayerViewPointRotator
	);

	// Add reach vector in direction player is looking
	return PlayerViewPointLocation + (PlayerViewPointRotator.Vector() * Reach);
}


