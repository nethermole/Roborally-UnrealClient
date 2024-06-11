// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UCLASS()
class ROBORALLY_UI_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int x;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString element;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString coords;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
