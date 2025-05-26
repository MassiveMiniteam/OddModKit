#include "LocGauntletTest.h"

ULocGauntletTest::ULocGauntletTest() {
    this->TestMaxDurationBeforeTimeout = 30.00f;
    this->bActivateCheckSuccessTimer = false;
    this->SuccessCheckTimerInterval = 3.00f;
    this->SuccessCheckTimerInitialDelay = 10.00f;
    this->bActivateBenchmark = false;
    this->bBenchmarkFPSChart = false;
}

bool ULocGauntletTest::TimerCheckForSuccess_Implementation(ETestExitCode& OutCheckResult) {
    return false;
}

void ULocGauntletTest::Tick_Implementation(float DeltaTime) {
}

void ULocGauntletTest::StopTestWithRuntimeErrorAndLog(const FString& NewLog) {
}

void ULocGauntletTest::StopTest(ETestExitCode ExitCode) {
}

void ULocGauntletTest::OnSuccessCheckTimerFired() {
}


void ULocGauntletTest::LogError(const FString& NewLog) {
}

void ULocGauntletTest::log(const FString& NewLog) {
}

FString ULocGauntletTest::CreateAndGetBenchmarkFolder() {
    return TEXT("");
}


