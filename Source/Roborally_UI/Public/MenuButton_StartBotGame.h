// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"

#include "MenuButton_StartBotGame.generated.h"


UCLASS()
class ROBORALLY_UI_API AMenuButton_StartBotGame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMenuButton_StartBotGame();

	UFUNCTION(BlueprintCallable)
	virtual void CreateBotGame();

	void Callback_CreateBotGame(FHttpRequestPtr request, FHttpResponsePtr response, bool connectedSuccessfully);

	virtual void StartBotGame(FString gameId);

	void Callback_StartBotGame(FHttpRequestPtr request, FHttpResponsePtr response, bool connectedSuccessfully);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
