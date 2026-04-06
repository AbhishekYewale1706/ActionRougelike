// Fill out your copyright notice in the Description page of Project Settings.


#include "RougePlayerControllerBase.h"

#include "ActionRougelike/Components/RougeInteractionComponentBase.h"

ARougePlayerControllerBase::ARougePlayerControllerBase()
{
	RougeInteractionComponent=CreateDefaultSubobject<URougeInteractionComponentBase>(TEXT("RougeInteractionComponent"));
	
}
