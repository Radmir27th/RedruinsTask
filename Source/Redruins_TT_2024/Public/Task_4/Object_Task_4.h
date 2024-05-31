// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Object_Task_4.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta = (ShowWorldContextPin))
class REDRUINS_TT_2024_API UObject_Task_4 : public UObject
{
	GENERATED_BODY()

public:

	virtual UWorld* GetWorld() const override;

	virtual bool IsSupportedForNetworking() const override { return true; };

	virtual bool IsNameStableForNetworking() const override { return false; };


	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:

	UPROPERTY(Replicated)
		FName ItemName;
	UPROPERTY(Replicated)
		int32 ItemStackAmount;

public:

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = ItemInfo)
		void SetItemName(const FName& NewName) { ItemName = NewName; };

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = ItemInfo)
		void SetItemStackAmount(const int32& NewStackAmount) { ItemStackAmount = NewStackAmount;  };

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = ItemInfo)
		FName GetItemName() const { return ItemName;  };

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = ItemInfo)
		int32 GetItemStackAmount() const { return ItemStackAmount; }



	
};
