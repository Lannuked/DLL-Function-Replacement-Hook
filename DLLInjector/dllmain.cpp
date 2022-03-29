#include "pch.h"
#include "FunctionDefinitions.h"

//By Lannuked

//CurrentAddress = Address inside of the exe in which you want to replace
//DestinationAddress = Address which the JMP will point to
BOOL patchMemory(int CurrentAddress, int DestinationAddress) {
	
	//Let us do stuff!
	DWORD access = PROCESS_VM_WRITE | PROCESS_VM_OPERATION;
	
	//Get the processID of Roblox.exe
	DWORD processID = GetCurrentProcessId();
	
	//Get the roblox.exe process and give us access
	HANDLE procHandle = OpenProcess(access, FALSE, processID);

	//Turn that vector into a char!
	vector<unsigned char> GetAddress = mkjmp(CurrentAddress, DestinationAddress);
	const unsigned char* WriteThis(&GetAddress[0]);
	
	//Finally, write our address to memory!
	SIZE_T writtenMem;
	WriteProcessMemory(procHandle, (LPVOID)CurrentAddress, (LPCVOID)WriteThis, 5, &writtenMem);

	//Let's get outta here!
	CloseHandle(procHandle);
	return true;
}

static bool didonce = false;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	//Make sure this only runs once
	if (!didonce)
	{
		didonce = true;
		//Write our jmp instruction
		patchMemory(0x00450170, (int)addressof(PlayASound));
	}
	return TRUE;
}
