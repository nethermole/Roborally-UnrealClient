// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CreateGameDTO.generated.h"

USTRUCT(BlueprintType, Category = "Kyle")
struct FDTOCreateGame {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	FString gameId;
};

/**
 * 
 */
UCLASS()
class ROBORALLY_UI_API UCreateGameDTO : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UCreateGameDTO();
	~UCreateGameDTO();

	UFUNCTION(BlueprintCallable, Category = "Kyle")
	static FDTOCreateGame ReadJson(FString inputString);
};
