// RedRuins Softworks (c)


#include "Task_4/Object_Task_4.h"
#include "Net/UnrealNetwork.h"

UWorld* UObject_Task_4::GetWorld() const
{
	if (!GetOuter()) return nullptr;

	return GetOuter()->GetWorld();
}

void UObject_Task_4::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	
	DOREPLIFETIME(UObject_Task_4, ItemName);
	DOREPLIFETIME(UObject_Task_4, ItemStackAmount);

	
	UBlueprintGeneratedClass* Blueprint = Cast<UBlueprintGeneratedClass>(GetClass());
	if (Blueprint) Blueprint->GetLifetimeBlueprintReplicationList(OutLifetimeProps);
	
}
