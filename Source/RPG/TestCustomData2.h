// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TestCustomData2.generated.h"

USTRUCT(BlueprintType)
struct FTestCustomData2 : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:


	UPROPERTY(BlueprintReadOnly, Category = "TestCustomData")
		int32 SomeNumber;

	UPROPERTY(BlueprintReadOnly, Category = "TestCustomData")
		FString SomeString;
};

