// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Widget/BSInput.h"
#include "BSPlayerController.generated.h"

class UBSInput;
class UUserWidget;

/**
 * 
 */
UCLASS()
class HW09_API ABSPlayerController : public APlayerController
{
	GENERATED_BODY()


public:

	ABSPlayerController();
	virtual void BeginPlay() override;

	void SetChatMessageString(const FString& InChatMessageString);
	
	void PrintChatMessageString(const FString& InChatMessageString);
	
	UFUNCTION(Client, Reliable)
	void ClientRPCPrintChatMessageString(const FString& InChatMessageString);
    
	UFUNCTION(Server, Reliable)
	void ServerRPCPrintChatMessageString(const FString& InChatMessageString);

	UPROPERTY(Replicated, BlueprintReadOnly)
	FText NotificationText;
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UBSInput> ChatInputWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UBSInput> ChatInputWidgetInstance;
	
	FString ChatMessageString;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> NotificationTextWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UUserWidget> NotificationTextWidgetInstance;
};
