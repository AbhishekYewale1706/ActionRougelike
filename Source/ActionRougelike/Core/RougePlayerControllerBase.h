// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RougePlayerControllerBase.generated.h"

class URougeInteractionComponentBase;
/**
 * 
 */
UCLASS()
class ACTIONROUGELIKE_API ARougePlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly,Category="Components")
	TObjectPtr<URougeInteractionComponentBase>RougeInteractionComponent;
	
public:
	ARougePlayerControllerBase();
};
