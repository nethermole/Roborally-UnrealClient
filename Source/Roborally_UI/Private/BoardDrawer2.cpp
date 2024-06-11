// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardDrawer2.h"
#include "UjJsonReader.h"

#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"



// Sets default values
ABoardDrawer2::ABoardDrawer2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//AddToRoot();
	UE_LOG(LogTemp, Log, TEXT("logging works maybe????"))

}


void ABoardDrawer2::GetBoardInfo_TriggersDrawBoard(FString gameId) {
	UE_LOG(LogTemp, Log, TEXT("GameId: %s"), *gameId)

	FHttpRequestRef request = FHttpModule::Get().CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &ABoardDrawer2::DrawBoard);
	request->SetURL("http://localhost:8080/board/admin");
	request->SetVerb("GET");
	request->ProcessRequest();
}

void ABoardDrawer2::DrawBoard(FHttpRequestPtr request, FHttpResponsePtr response, bool connectedSuccessfully) {
	UE_LOG(LogTemp, Log, TEXT("entered drawboard: %s"), *response->GetContentAsString());

	UjJsonReader* jsonReader = NewObject<UjJsonReader>(UjJsonReader::StaticClass());
	FDTOBoard dtoBoard = jsonReader->ReadJson(*response->GetContentAsString());

	UE_LOG(LogTemp, Log, TEXT("Board width %s"), *FString::FromInt(dtoBoard.width));
	UE_LOG(LogTemp, Log, TEXT("0,0 tile has element: %s"), *dtoBoard.squares[0].tile.elements[0].elementEnum);

	double TileSideLength = 100.0;

	for (int i = 0; i < dtoBoard.squares.Num(); i++) {
		FDTOSquare dtoSquare = dtoBoard.squares[i];
		
		int x = dtoSquare.y;	//this is intentional. blame unreal for deciding x is "up", and y is "right"
		int y = dtoSquare.x;	//this is intentional. blame unreal for deciding x is "up", and y is "right"

		int topLevelWithFloor = -50;
		FTransform location = FTransform(FVector(x * TileSideLength, y * TileSideLength, topLevelWithFloor));

		ATile* blueprintTileRef = GetWorld()->SpawnActorDeferred<ATile>(blueprintTile, location);
		blueprintTileRef->x = x;
		blueprintTileRef->y = y;

		blueprintTileRef->coords = FString::FromInt(x) + "," + FString::FromInt(y);

		for (FDTOElement element : dtoSquare.tile.elements) {
			if (!element.elementEnum.Contains(TEXT("WALL"))) {
				blueprintTileRef->element = element.elementEnum;
				break;
			}
		}
		
		blueprintTileRef->FinishSpawning(location);
	}

}


// Called when the game starts or when spawned
void ABoardDrawer2::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABoardDrawer2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

