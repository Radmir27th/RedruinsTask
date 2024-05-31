// RedRuins Softworks (c)


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetWorld() && GetController()) 
	{
		FVector ViewLocation;
		FRotator ViewRotation;

		GetController()->GetPlayerViewPoint(ViewLocation, ViewRotation);
		const FVector LineDirection = ViewRotation.Vector();
		const FVector TraceEnd = ViewLocation + LineDirection * 500;

		GetWorld()->LineTraceSingleByChannel(HitResult, ViewLocation, TraceEnd, ECollisionChannel::ECC_Visibility);

	}

	

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

