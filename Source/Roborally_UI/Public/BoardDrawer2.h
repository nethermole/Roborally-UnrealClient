// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "Tile.h"

#include "BoardDrawer2.generated.h"

UCLASS()
class ROBORALLY_UI_API ABoardDrawer2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoardDrawer2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void GetBoardInfo_TriggersDrawBoard(FString gameId);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Kyle")
	TSubclassOf<class ATile> blueprintTile;

	void DrawBoard(FHttpRequestPtr request, FHttpResponsePtr response, bool connectedSuccessfully);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
