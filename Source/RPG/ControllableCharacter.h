// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Object.h"
#include "ControllableCharacter.generated.h"

UINTERFACE()

class RPG_API UControllableCharacter : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class RPG_API IControllableCharacter
{
	GENERATED_IINTERFACE_BODY()

	virtual void MoveVertical(float Value);
	virtual void MoveHorizontal(float Value);
};
