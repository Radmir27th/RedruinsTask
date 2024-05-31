// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class UObject_Task_4;

UCLASS()
class REDRUINS_TT_2024_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual bool ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags) override;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = Reps)
		UObject_Task_4 *RepObject;

	TArray<UObject*> RepObjectList;

	ELifetimeCondition AllowActorComponentToReplicate(const UActorComponent* ComponentToReplicate) const override;
	
	UFUNCTION(BlueprintCallable)
		void ReplicateDynamicComponent(UActorComponent* ComponentToReplicate);
};
