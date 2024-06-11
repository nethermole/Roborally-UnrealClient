// Fill out your copyright notice in the Description page of Project Settings.


#include "UjJsonReader.h"

#include "JsonObjectConverter.h"

FDTOBoard UjJsonReader::ReadJson(FString inputString) {
	TSharedPtr<FJsonObject> jsonObject;
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(inputString), jsonObject)) {
		UE_LOG(LogTemp, Log, TEXT("could not deserialize board to object"));
	}

	FDTOBoard dtoBoard;

	if (!FJsonObjectConverter::JsonObjectToUStruct<FDTOBoard>(jsonObject.ToSharedRef(), &dtoBoard)) {
		UE_LOG(LogTemp, Log, TEXT("could not deserialize board to struct"));
	}

	return dtoBoard;
}
