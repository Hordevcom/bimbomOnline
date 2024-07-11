// Fill out your copyright notice in the Description page of Project Settings.


#include "BimBomOnline/tests/SimpleTests.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Kismet/GameplayStatics.h"
#include "BimBomOnline/TestActor.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestPublicVariable, "BimBomOnline.TestPublicVariable",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority)

bool FTestPublicVariable::RunTest(const FString& Parameters)
{
	AddInfo("Test that!");
	ATestActor testActor;
	TestTrueExpr(testActor.TestPublicVariable == 100);
	
	return true;
}