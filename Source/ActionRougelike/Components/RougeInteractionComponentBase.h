
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RougeInteractionComponentBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACTIONROUGELIKE_API URougeInteractionComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	URougeInteractionComponentBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
