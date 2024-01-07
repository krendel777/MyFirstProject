// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All , All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::printTypes()
{
	UE_LOG(LogTemp, Display, TEXT("Hello UNREAL ENGINE 5 !!!"));
	UE_LOG(LogTemp, Warning, TEXT("Hello UNREAL ENGINE 5 !!!"));
	UE_LOG(LogTemp, Error, TEXT("Hello UNREAL ENGINE 5 !!!"));
	UE_LOG(LogTemp, Error, TEXT("testF: %f;  testI: %d;  testB: %d"), 1.23, 4, true);
}

void ABaseGeometryActor::printStringTypes()
{
	FString Name = "Jonh Connor";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	int WeaponNum = 4;
	float Health = 34.43;
	bool IsDead = false;

	FString WeaponNumStr = "Weapons num = " + FString::FromInt(WeaponNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "IsDead = " + FString(IsDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT(" \n == All Stat == \n %s \n %s \n %s"), *WeaponNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stat, true, FVector2D(1.5f, 1.5f));
}

