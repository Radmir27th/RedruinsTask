// RedRuins Softworks (c)


#include "BaseCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Task_4/Object_Task_4.h"
#include "Engine/ActorChannel.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		RepObject = NewObject<UObject_Task_4>(this);
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABaseCharacter, RepObject);

	UBlueprintGeneratedClass* Blueprint = Cast<UBlueprintGeneratedClass>(GetClass());
	if (Blueprint) Blueprint->GetLifetimeBlueprintReplicationList(OutLifetimeProps);
	
}

bool ABaseCharacter::ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	bool bIsSuccess = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);

	if (RepObject)
		bIsSuccess |= Channel->ReplicateSubobject(RepObject, *Bunch, *RepFlags);
	return bIsSuccess;
}

ELifetimeCondition ABaseCharacter::AllowActorComponentToReplicate(const UActorComponent* ComponentToReplicate) const
{
	Super::AllowActorComponentToReplicate(ComponentToReplicate);
	return ELifetimeCondition::COND_Dynamic;
}

void ABaseCharacter::ReplicateDynamicComponent(UActorComponent* ComponentToReplicate)
{
	AllowActorComponentToReplicate(ComponentToReplicate);

	SetReplicatedComponentNetCondition(ComponentToReplicate, COND_None);
}



