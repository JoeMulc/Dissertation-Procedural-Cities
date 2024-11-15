// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadGenerator.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARoadGenerator::ARoadGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoadGenerator::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARoadGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<FRoad> ARoadGenerator::GenerateRoads()
{
	UE_LOG(LogTemp, Warning, TEXT("Started!"));

	TArray<FRoad> finalNetwork;

	TArray<FProposedRoad*> propQ;

	FProposedRoad* initRoad = new FProposedRoad();
	FRoad* initSeg = new FRoad();

	initSeg->Start = FVector(0, 0, 0);
	initSeg->End = initSeg->Start + roadStep;
	initSeg->turnPoint = roadStep;
	initSeg->roadType = ERoadType::Main;

	initRoad->segment = initSeg;
	initRoad->rotator = FRotator(0, 0, 0);
	initRoad->varianceRotor = FRotator(0, 0, 0);
	initRoad->roadLength = 1.f;

	propQ.Push(initRoad);
	while (propQ.Num() > 0 && finalNetwork.Num() < maxRoads)
	{
		FProposedRoad* current = propQ.Last();

		propQ.Pop();

		//Need a placement check

		if (CheckConstraints(finalNetwork, current, propQ))
		{
			finalNetwork.Push(*current->segment);
			AddRoads(propQ, current);

		}

		delete(current->segment);
		delete(current);
		//UE_LOG(LogTemp, Display, TEXT("Q size - %i"), propQ.Num());
		//UE_LOG(LogTemp, Display, TEXT("Rand - %f"), randFloat());
	}

	UE_LOG(LogTemp, Warning, TEXT("Finished!"));
	return finalNetwork;
}

void ARoadGenerator::AddRoads(TArray<FProposedRoad*>& segQ, FProposedRoad* current)
{
	//Generate forward road if max length not reached		added some variance in size dont know if i like this + FMath::RandRange(-5, 5)

	switch (current->segment->roadType)
	{
	case(ERoadType::Main):

		if (current->roadLength <= maxMainRoadLength + FMath::RandRange(-maxMainRoadLength / 10, maxMainRoadLength/ 10))
		{
			AddForwardRoad(segQ, current, ERoadType::Main);
		}
		else if (current->segment->roadType == ERoadType::Main)
		{
			float decider = FMath::RandRange(0, 100);
			//UE_LOG(LogTemp, Display, TEXT("HERE! %f"), decider);
			if (decider > 35)
			{
				UE_LOG(LogTemp, Display, TEXT("Splitting!"));
				AddRoadSide(segQ, current, true, ERoadType::Main);
				AddRoadSide(segQ, current, false, ERoadType::Main);
			}
			//chance road continues
			if (decider < 65)
			{
				UE_LOG(LogTemp, Display, TEXT("Onwards!"));
				current->roadLength = 1;
				AddForwardRoad(segQ, current, ERoadType::Main);
			}
		}
		break;

	case(ERoadType::Secondary):

		if (current->roadLength <= MaxSecondaryRoadLength)
		{
			AddForwardRoad(segQ, current, ERoadType::Secondary);
		}
		break;

	case(ERoadType::Coastal):
		//UE_LOG(LogTemp, Display, TEXT("Coastal!"));
		if (current->roadLength <= 400)
		{
			AddForwardRoad(segQ, current, ERoadType::Coastal);
		}
		break;
	}

	
	if (randFloat() < mainRoadBranchChance && branchCounter <= branchCap && current->segment->roadType != ERoadType::Secondary)
	{
		if (randFloat() < 0.5)
		{
			AddRoadSide(segQ, current, true, ERoadType::Secondary);
		}
		else
		{
			AddRoadSide(segQ, current, false, ERoadType::Secondary);
		}
	}
	else if (randFloat() < secondaryRoadBranchChance && branchCounter <= branchCap && current->segment->roadType == ERoadType::Secondary)
	{
		if (randFloat() < 0.5)
		{
			AddRoadSide(segQ, current, true, ERoadType::Secondary);
		}
		else
		{
			AddRoadSide(segQ, current, false, ERoadType::Secondary);
		}
	}
	
}

void ARoadGenerator::AddForwardRoad(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, ERoadType newType)
{
	//UE_LOG(LogTemp, Display, TEXT("ForwardRoad"));

	FProposedRoad* newPropRoad = new FProposedRoad();
	FRoad* newSeg = new FRoad();

	FRoad* prevSeg = previous->segment;

	intensity = newType == ERoadType::Main ? mainRoadIntensity : secondaryRoadIntensity;

	newPropRoad->varianceRotor = previous->varianceRotor + FRotator(0, intensity * (randFloat() - 0.5f), 0);
	newPropRoad->rotator = previous->rotator + newPropRoad->varianceRotor;

	newSeg->Start = prevSeg->End;
	newSeg->End = newSeg->Start + newPropRoad->rotator.RotateVector(roadStep);
	newSeg->turnPoint = prevSeg->End - prevSeg->Start;
	newSeg->roadType = newType;
	
	newPropRoad->segment = newSeg;
	newPropRoad->roadLength = previous->roadLength + 1;

	segQ.Push(newPropRoad);
}

void ARoadGenerator::AddRoadSide(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, bool left, ERoadType newType)
{
	FProposedRoad* newPropRoad = new FProposedRoad();
	FRoad* newSeg = new FRoad();

	FRoad* prevSeg = previous->segment;

	intensity = newType == ERoadType::Main ? mainRoadIntensity : secondaryRoadIntensity;

	newPropRoad->varianceRotor = FRotator(0, intensity * (randFloat() - 0.5f), 0);
	FRotator direction = left ? FRotator(0, 270, 0) : FRotator(0, 90, 0);
	newPropRoad->rotator = previous->rotator + newPropRoad->varianceRotor + direction;

	FVector offsetDirection = left ? newPropRoad->rotator.RotateVector(FVector(200, 0, 0)) : newPropRoad->rotator.RotateVector(FVector(-200, 0, 0));
	newSeg->Start = (prevSeg->End - prevSeg->Start) / 2 + prevSeg->Start + offsetDirection;
	newSeg->End = newSeg->Start + newPropRoad->rotator.RotateVector(roadStep);
	newSeg->turnPoint = newSeg->End - newSeg->Start;
	newSeg->roadType = newType;

	newPropRoad->segment = newSeg;
	newPropRoad->roadLength = 1;
	segQ.Push(newPropRoad);

}

bool ARoadGenerator::CheckConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current, TArray<FProposedRoad*>& segQ)
{
	return CheckGlobalConstraints(finalNetwork, current, segQ);
}

bool ARoadGenerator::CheckGlobalConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current, TArray<FProposedRoad*>& segQ)
{
	//Get centre of proposed road
	FVector propMid = (current->segment->End - current->segment->Start) / 2 + current->segment->Start;

	// For each road in the final network
	for (const FRoad road : finalNetwork)
	{
		//get centre of final road to be compared
		FVector finalMid = (road.End - road.Start) / 2 + road.Start;
		
		//Check distance based on road size - magic number here fix me!!!!!!!
		if (FVector::Dist(finalMid, propMid) < 150 && current->segment->roadType != ERoadType::Coastal)
		{
			UE_LOG(LogTemp, Display, TEXT("OVERLAP"));
			return false;
		}
	}
														//REALLY SHOULD BE CHECKING FOR NULLPTRS
	//For each water volume
	for (AActor* w : water)
	{
		AVolume* waterVolume = Cast<AVolume>(w);
		
		//If proposed road is within the volume
		if (waterVolume->EncompassesPoint(current->segment->End + (current->segment->End - current->segment->Start) * 10, 75.f))
		{
			UE_LOG(LogTemp, Display, TEXT("Water!"));
			if (current->segment->roadType == ERoadType::Main || current->segment->roadType == ERoadType::Coastal)
			{
				bool coastalCreated = false;
				double angle = (FMath::Atan2((current->segment->Start - current->segment->End).X, (current->segment->Start - current->segment->End).Y)) * 180 / 3.14;
				angle = angle + 90;
				if (angle < 0)
				{
					angle = 360 + angle;
				}
				else if (angle > 360)
				{
					angle = angle - 360;
				}

				UE_LOG(LogTemp, Warning, TEXT("Angle %f!"), angle);

				while (!coastalCreated || angle >= 360)
				{
					
					current->segment->End = current->segment->Start + (current->segment->End - current->segment->Start).RotateAngleAxis(angle, FVector(0, 0, -1));
		
					if (!waterVolume->EncompassesPoint(current->segment->End + (current->segment->End - current->segment->Start) * 10, 75.f))
					{
						UE_LOG(LogTemp, Display, TEXT("L!"));
						current->segment->roadType = ERoadType::Coastal;
						current->segment->turnPoint = current->segment->End - current->segment->Start;
						current->rotator = FRotator(0, angle, 0);
						current->roadLength = 1;
						coastalCreated = true;
					}

				
					angle = angle + 1;
				}
			}
			else
			{
				return false;
			}
		}
		//else if (waterVolume->EncompassesPoint(current->segment->Start, 75.f))
		//{
		//	return false;
		//}
		//if (waterVolume->EncompassesPoint(current->segment->End + (current->segment->End - current->segment->Start) * 5, 75.f))
		//{
		//	current->segment->roadType = ERoadType::Coastal;
		//}
	}

	return true;
}

float ARoadGenerator::randFloat()
{
	//FMath::RandRange(0, 1)
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}
