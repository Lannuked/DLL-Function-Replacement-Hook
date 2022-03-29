#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#include <tlhelp32.h>
#include <sstream>
#pragma comment(lib, "winmm.lib")
using namespace std;

vector<unsigned char> mkjmp(int, int);
void PlayASound();