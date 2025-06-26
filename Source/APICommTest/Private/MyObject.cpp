// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"
#define LIVE_URL_BASE "https://titleId.playfabapi.com/Client/RegisterPlayFabUser"

void AHTTPRequest::BeginPlay()
{
    Super::BeginPlay();
    //SendHttpRequest(TEXT("https://titleId.playfabapi.com/Client/RegisterPlayFabUser"),0); 
}


void AHTTPRequest::SendHttpRequest(const FString& InURL,EHttpVerb InVerb, const FString& InBody)
{
    // Obtener el módulo HTTP de Unreal
    FHttpModule& HttpModule = FHttpModule::Get();

    // Crear una nueva solicitud HTTP
    TSharedRef<IHttpRequest> Request = HttpModule.CreateRequest();

    // Configurar la solicitud
    Request->SetVerb(HttpVerbs[static_cast<size_t>(InVerb)]);  // Método HTTP
    Request->SetURL(InURL);  // URL de la API
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));  // Tipo de contenido esperado

    // Asignar la función de callback cuando la solicitud se complete
    Request->OnProcessRequestComplete().BindUObject(this, &AHTTPRequest::OnResponseReceived);

    // Enviar la solicitud
    Request->ProcessRequest();
}

void AHTTPRequest::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (!bWasSuccessful || !Response.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("Request failed!"));
        return;
    }

    // Obtener el contenido de la respuesta
    FString ResponseString = Response->GetContentAsString();
    UE_LOG(LogTemp, Log, TEXT("Response: %s"), *ResponseString);

    // Intentar parsear el JSON
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseString);

    if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
    {
        FString Title = JsonObject->GetStringField("title");
        bool bCompleted = JsonObject->GetBoolField("completed");

        UE_LOG(LogTemp, Log, TEXT("Title: %s"), *Title);
        UE_LOG(LogTemp, Log, TEXT("Completed: %s"), bCompleted ? TEXT("true") : TEXT("false"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to parse JSON response"));
    }
}
