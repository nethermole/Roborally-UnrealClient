// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UjJsonReader.generated.h"


USTRUCT(BlueprintType, Category = "Kyle")
struct FDTOElement {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	FString elementEnum;
};

USTRUCT(BlueprintType, Category = "Kyle")
struct FDTOTile {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	TArray<FDTOElement> elements;
};

USTRUCT(BlueprintType, Category = "Kyle")
struct FDTOSquare {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	int x;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	int y;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	FDTOTile tile;
};

USTRUCT(BlueprintType, Category = "Kyle")
struct FDTOBoard {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	int width;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	int height;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Kyle")
	TArray<FDTOSquare> squares;
};



/**
 * 
 */
UCLASS()
class ROBORALLY_UI_API UjJsonReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Kyle")
	static FDTOBoard ReadJson(FString inputString);

};
