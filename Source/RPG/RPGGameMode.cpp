// Fill out your copyright notice in the Description page of Project Settings.

#include "RPGGameMode.h"
#include "RPGPlayerController.h"
#include "RPGCharacter.h"
#include "RPGGameInstance.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ARPGGameMode::ARPGGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = ARPGPlayerController::StaticClass();
	DefaultPawnClass = ARPGCharacter::StaticClass();
}

void ARPGGameMode::BeginPlay()
{
	Cast<URPGGameInstance>(GetGameInstance())->Init();
}

void ARPGGameMode::Tick(float DeltaTime)
{
	if (this->currentCombatInstance != nullptr)
	{
		bool combatOver = this->currentCombatInstance->Tick(DeltaTime);
		if (combatOver)
		{
			if (this->currentCombatInstance->phase == CombatPhase::CPHASE_GameOver)
			{
				UE_LOG(LogTemp, Log, TEXT("Player loses combat, game over" ) );
			}
			else if (this->currentCombatInstance->phase == CombatPhase::CPHASE_Victory)
			{
				UE_LOG(LogTemp, Log, TEXT("Player wins combat"));
			}
			// enable player actor
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(true);
			delete(this->currentCombatInstance);
			this->currentCombatInstance = nullptr;
			this->enemyParty.Empty();
		}
	}
}

void ARPGGameMode::TestCombat()
{
	// locate enemies asset
	UDataTable* enemyTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game / Data / Enemies.Enemies'" ) ) );
	if (enemyTable == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemies data table not found!"));
		return;
	}

	// locate enemy
	FEnemyInfo* row = enemyTable->FindRow<FEnemyInfo>(TEXT("S1"),TEXT("LookupEnemyInfo"));
	if (row == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemy ID 'S1' not found!"));
		return;
	}

	// disable player actor
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(false);

	// add character to enemy party
	UGameCharacter* enemy = UGameCharacter::CreateGameCharacter(row, this);
	this->enemyParty.Add(enemy);

	URPGGameInstance* gameInstance = Cast<URPGGameInstance>(GetGameInstance());

	this->currentCombatInstance = new CombatEngine(gameInstance->PartyMembers, this->enemyParty);

	UE_LOG(LogTemp, Log, TEXT("Combat started"));
}