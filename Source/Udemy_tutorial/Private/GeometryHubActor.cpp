// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryHubActor.h"
#include <Engine/World.h>

// Sets default values
AGeometryHubActor::AGeometryHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();
	
	DoActorSpawn1();
	DoActorSpawn2();
	DoActorSpawn3();

}

// Called every frame
void AGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGeometryHubActor::DoActorSpawn1()
{
	UWorld* World = GetWorld();
	if (World)
	{
		int32 Column = ArrayLength.Column_length;
		int32 Row = ArrayLength.Row_length;
		for (int32 i = 0; i < Column; ++i) {
			for (int32 j = 0; j < Row ; ++j) {
				const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator,
					FVector(90.0f * i, 80.0f * j, 100.0f));
				ABaseGeometryActor* Geometry = World->SpawnActor<ABaseGeometryActor>(GeometryConmiro, GeometryTransform);

				if (Geometry)
				{
					FGeometryDataConmiro Data;
					Data.MoveType = FMath::RandBool() ? EMovementTypeConmiro::Sin : EMovementTypeConmiro::Static;
					Geometry->SetGeometryData(Data);
				}
			}
		}
	}
}

void AGeometryHubActor::DoActorSpawn2()
{
	UWorld* World = GetWorld();
	if (World)
	{
		int32 Column = ArrayLength.Column_length;
		int32 Row = ArrayLength.Row_length;
		for (int32 i = 0; i < Column; ++i) {
			for (int32 j = 0; j < Row; ++j) {
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator,
				FVector(90.0f * i, 80.0f * j, 150.0f));
			ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(GeometryConmiro, GeometryTransform);

			if (Geometry)
			{
				FGeometryDataConmiro Data;
				Data.MoveType = FMath::RandBool() ? EMovementTypeConmiro::Sin
					: EMovementTypeConmiro::Static;
				Data.Color = FLinearColor::MakeRandomColor();
				Geometry->SetGeometryData(Data);
				Geometry->FinishSpawning(GeometryTransform);
			}
		}
	}
}
}
void AGeometryHubActor::DoActorSpawn3()
{
	UWorld* World = GetWorld();
	if (World)
	{
	for (const FGeometryPayLoad Payload : GeometryPayloads)
	{
		ABaseGeometryActor* Geometry = World->SpawnActorDeferred<ABaseGeometryActor>(Payload.GeometryConmiro, Payload.InitialTransform);
		if (Geometry)
		{
			Geometry->SetGeometryData(Payload.Data);
			Geometry->FinishSpawning(Payload.InitialTransform);
		}
	}
}
}

