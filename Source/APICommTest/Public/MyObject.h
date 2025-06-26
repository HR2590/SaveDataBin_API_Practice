// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"

#include "MyObject.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EHttpVerb : uint8
{
	GET = 0,
	POST
	
};

UCLASS()
class APICOMMTEST_API AHTTPRequest : public AActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;


	void SendHttpRequest(const FString& InURL,EHttpVerb InVerb, const FString& InBody);
	// Callback para manejar la respuesta de la solicitud HTTP
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
private:
	TArray<FString> HttpVerbs={"GET","POST"};
};


