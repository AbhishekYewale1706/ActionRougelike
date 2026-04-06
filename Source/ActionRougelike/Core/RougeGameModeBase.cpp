// Fill out your copyright notice in the Description page of Project Settings.


#include "RougeGameModeBase.h"

#include "RougePlayerControllerBase.h"
#include "ActionRougelike/CharacterBase/RougeCharacter.h"

ARougeGameModeBase::ARougeGameModeBase()
{
	PlayerControllerClass=ARougePlayerControllerBase::StaticClass();
	
}
