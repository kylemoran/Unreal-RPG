// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "MyActor2.generated.h"

USTRUCT(BlueprintType)
struct FThisNewStructure : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = test)
		int32 SomeNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = test)
		FString SomeString;

};
