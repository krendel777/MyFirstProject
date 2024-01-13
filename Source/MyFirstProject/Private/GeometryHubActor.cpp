// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryHubActor.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(LogGeometryHub, All, All)

// Sets default values
AGeometryHubActor::AGeometryHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AGeometryHubActor::DoActorSpawn1()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (int32 i = 0; i < 10; ++i)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 300.0f));
			ABaseGeometryActor* GeometryActor = World->SpawnActor<ABaseGeometryActor>(GeometryClass, GeometryTransform);
			if (GeometryActor)
			{
				FGeometryData Data;
				Data.MoveType = FMath::RandBool() ? EMovementType::Sin : EMovementType::Static;
				GeometryActor->SetGeometryData(Data);
			}
		}
	}
}

void AGeometryHubActor::DoActorSpawn2()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (int32 i = 0; i < 10; ++i)
		{
			const FTransform GeometryTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 700.0f));
			ABaseGeometryActor* GeometryActor = World->SpawnActorDeferred<ABaseGeometryActor>(GeometryClass, GeometryTransform);
			if (GeometryActor)
			{
				FGeometryData Data;
				Data.Color = FLinearColor::MakeRandomColor();
				Data.MoveType = FMath::RandBool() ? EMovementType::Sin : EMovementType::Static;
				GeometryActor->SetGeometryData(Data);
			}
		}
	}
}

void AGeometryHubActor::DoActorSpawn3()
{
	UWorld* World = GetWorld();
	if (World)
	{
		for (const FGeometryPayload& Payload : GeometryPayloads)
		{
			ABaseGeometryActor* GeometryActor = World->SpawnActorDeferred<ABaseGeometryActor>(Payload.GeometryClass, Payload.InitialTransform);
			if (GeometryActor)
			{
				GeometryActor->SetGeometryData(Payload.GeometryData);
				GeometryActor->OnColorChanged.AddDynamic(this, &AGeometryHubActor::OnColorChanged);
				GeometryActor->OnTimerFinished.AddUObject(this, &AGeometryHubActor::OnTimerFinished);
				GeometryActor->FinishSpawning(Payload.InitialTransform);
			}
		}
	}
}

void AGeometryHubActor::OnColorChanged(const FLinearColor& Color, const FString& Name)
{
	UE_LOG(LogGeometryHub, Warning, TEXT("Actor name: %s,  Color: %s"), *Name, *Color.ToString());
}

void AGeometryHubActor::OnTimerFinished(AActor* Actor)
{
	if (!Actor) return;
	
	UE_LOG(LogGeometryHub, Error, TEXT("Timer finished: %s"), *Actor->GetName());

	ABaseGeometryActor* GeometryActor = Cast<ABaseGeometryActor>(Actor);
	if(GeometryActor)
		UE_LOG(LogGeometryHub, Display, TEXT("Cast is success \nStats: \n%s"), *GeometryActor->GetGeometryData().GetStats());

	GeometryActor->Destroy(); 
}

// Called when the game starts or when spawned
void AGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();
	
	//DoActorSpawn1();
	//DoActorSpawn2();
	DoActorSpawn3();
}

// Called every frame
void AGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

