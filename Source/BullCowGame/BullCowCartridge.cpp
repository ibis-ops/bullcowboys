// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The Hidden word is: %s."), *HiddenWord); // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking player guess
    {
        ProcessGuess(Input);
    } 
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cows"));
    
    HiddenWord = TEXT("cum"); 
    LivesNumber = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), LivesNumber);
    PrintLine(TEXT("Type in your guess. \npress ENTER to contiue...."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("GAME OVER BOI!"));
    PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if(Guess == HiddenWord)
    {
        PrintLine(TEXT("You won!"));
        EndGame();
    }
    else
    {
        if (HiddenWord.Len() != Guess.Len())
        {
            PrintLine(TEXT("Word guess wrong length!"));
            return;
        }
        else
        {
            --LivesNumber;
            PrintLine(TEXT("You have lost a life try again."));
            PrintLine(TEXT("You now have %i lives"), LivesNumber);
            //Comment?
            
            if (LivesNumber == 0)
            {
                EndGame();
            }
        }
    }       
}