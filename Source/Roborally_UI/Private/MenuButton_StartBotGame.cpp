// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuButton_StartBotGame.h"

#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"

#include "CreateGameDTO.h"

// Sets default values
AMenuButton_StartBotGame::AMenuButton_StartBotGame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMenuButton_StartBotGame::CreateBotGame() {
	FHttpRequestRef request = FHttpModule::Get().CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &AMenuButton_StartBotGame::Callback_CreateBotGame);
	request->SetURL("http://localhost:8080/game/create");
	request->SetVerb("POST");
	request->SetHeader("Content-Type", "application/json");
	request->SetContentAsString(FString("{\"humanPlayers\": 0,\"botPlayers\" : 4,\"maxHandSize\" : 5}"));
	request->ProcessRequest();
}

void AMenuButton_StartBotGame::Callback_CreateBotGame(FHttpRequestPtr request, FHttpResponsePtr response, bool connectedSuccessfully){
	UE_LOG(LogTemp, Log, TEXT("entered Callback_StartBotGame"));

	UCreateGameDTO* jsonReader = NewObject<UCreateGameDTO>(UCreateGameDTO::StaticClass());
	FDTOCreateGame dtoCreateGame = jsonReader->ReadJson(*response->GetContentAsString());
	FString gameId = dtoCreateGame.gameId;

	UE_LOG(LogTemp, Log, TEXT("entered game created with id=%s"), *gameId);

	StartBotGame(gameId);
}

void AMenuButton_StartBotGame::StartBotGame(FString gameId) {
	UE_LOG(LogTemp, Log, TEXT("entered StartBotGame"));

	FHttpRequestRef request = FHttpModule::Get().CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &AMenuButton_StartBotGame::Callback_StartBotGame);
	request->SetURL("http://localhost:8080/game/" + gameId + "/start");
	request->SetVerb("POST");
	request->ProcessRequest();
}

void AMenuButton_StartBotGame::Callback_StartBotGame(FHttpRequestPtr request, FHttpResponsePtr response, bool connectedSuccessfully) {
	UE_LOG(LogTemp, Log, TEXT("entered Callback_StartBotGame"));
}

// Called when the game starts or when spawned
void AMenuButton_StartBotGame::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMenuButton_StartBotGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

