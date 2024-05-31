// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_1.generated.h"

class UDA_2;

USTRUCT(BlueprintType, Blueprintable)
struct FPlayer_Data
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FName PlayerName;
	UPROPERTY(EditDefaultsOnly)
	int32 PlayerScore;
	UPROPERTY(EditDefaultsOnly)
	UDA_2* DataAsset_2;
};

/**
 * 
 */
UCLASS(Blueprintable)
class REDRUINS_TT_2024_API UDA_1 : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
		FPlayer_Data Player;
	
};
