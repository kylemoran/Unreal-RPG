// Fill out your copyright notice in the Description page of Project Settings.

#include "MyNewActor.h"
#include "MyActor2.h"


// Sets default values
AMyNewActor::AMyNewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyNewActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello, world!"));
	if (DataTable != NULL)
	{
		FThisNewStructure* row = DataTable->FindRow<FThisNewStructure>(
			TEXT("2"), TEXT(" LookupTestCustomData"));
		FString someString = row->SomeString;
		UE_LOG(LogTemp, Warning, TEXT("%s"), *someString);
	}
}

// Called every frame
void AMyNewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

