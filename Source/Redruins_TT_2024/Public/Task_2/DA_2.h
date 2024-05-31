// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Task_2/DA_1.h"
#include "DA_2.generated.h"



UENUM(BlueprintType)
enum class ECondition : uint8
{
	value_true,
	value_false,
	value_none,

};
/**
 * 
 */
UCLASS(Blueprintable)
class REDRUINS_TT_2024_API UDA_2 : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
		ECondition Condition = ECondition::value_none;

	UPROPERTY(EditDefaultsOnly, meta = (EditCondition ="Condition == ECondition::value_true", EditConditionHides))
		UDA_1 *DataAsset_1;
	
};
