#include "pch.h"
#include "FunctionDefinitions.h"

//Just a simple function to demonstrate the functionality of addressof
//To use this, put an audio file named forest.wav inside the folder with Roblox.exe
void PlayASound()
{
    PlaySound(TEXT("forest.wav"), NULL, SND_FILENAME | SND_ASYNC);
}