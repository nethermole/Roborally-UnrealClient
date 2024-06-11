// Fill out your copyright notice in the Description page of Project Settings.


#include "CreateGameDTO.h"

#include "JsonObjectConverter.h"

UCreateGameDTO::UCreateGameDTO()
{
}

UCreateGameDTO::~UCreateGameDTO()
{
}

FDTOCreateGame UCreateGameDTO::ReadJson(FString inputString) {
	TSharedPtr<FJsonObject> jsonObject;
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(inputString), jsonObject)) {
		UE_LOG(LogTemp, Log, TEXT("could not deserialize inputString to FDTOCreateGame"));
	}

	FDTOCreateGame fdtoCreateGame;

	if (!FJsonObjectConverter::JsonObjectToUStruct<FDTOCreateGame>(jsonObject.ToSharedRef(), &fdtoCreateGame)) {
		UE_LOG(LogTemp, Log, TEXT("could not deserialize inputString to FDTOCreateGame"));
	}

	return fdtoCreateGame;
}
