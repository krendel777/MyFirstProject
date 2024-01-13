// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryGameModeBase.h"
#include "SandBoxPawn.h"

AGeometryGameModeBase::AGeometryGameModeBase()
{
	DefaultPawnClass = ASandBoxPawn::StaticClass();
}
