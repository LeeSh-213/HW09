// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BSGameModeBase.generated.h"

class ABSPlayerController;

/**
 * 
 */
UCLASS()
class HW09_API ABSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	
	void PrintChatMessageString(ABSPlayerController* InChattingPlayerController, const FString& InChatMessageString);

	virtual void OnPostLogin(AController* NewPlayer) override;	

	FString GenerateSecretNumber();

	bool IsGuessNumberString(const FString& InNumberString);

	FString JudgeResult(const FString& InSecretNumberString, const FString& InGuessNumberString);


	
protected:
	FString SecretNumberString;

	TArray<TObjectPtr<ABSPlayerController>> AllPlayerControllers;
};
