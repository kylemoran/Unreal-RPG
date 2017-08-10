// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPG.h"
#include "GameCharacter.h"

class UGameCharacter;

/**
 * 
 */
enum class CombatPhase : uint8
{
	CPHASE_Decision,
	CPHASE_Action,
	CPHASE_Victory,
	CPHASE_GameOver,
};

class RPG_API CombatEngine
{
	bool waitingForCharacter;
public:
	TArray<UGameCharacter*> combatantOrder;
	TArray<UGameCharacter*> playerParty;
	TArray<UGameCharacter*> enemyParty;
	CombatPhase phase;

protected:
	UGameCharacter* currentTickTarget;
	int tickTargetIndex;

public:
	CombatEngine(TArray<UGameCharacter*> playerParty,TArray<UGameCharacter*> enemyParty);
	~CombatEngine();
	bool Tick(float DeltaSeconds);

protected:
	void SetPhase(CombatPhase phase);
	void SelectNextCharacter();
};
