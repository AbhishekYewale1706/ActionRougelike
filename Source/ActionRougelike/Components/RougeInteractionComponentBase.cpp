
#include "RougeInteractionComponentBase.h"




URougeInteractionComponentBase::URougeInteractionComponentBase()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}

void URougeInteractionComponentBase::BeginPlay()
{
	Super::BeginPlay();


	
}

void URougeInteractionComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	APlayerController*PC=CastChecked<APlayerController>(GetOwner());
	
	FVector Center=PC->GetPawn()->GetActorLocation();
	DrawDebugBox(GetWorld(),Center,FVector(20.f),FColor::Red);
	
}

