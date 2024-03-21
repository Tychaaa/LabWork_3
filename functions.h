#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <Windows.h>

using namespace std;

// ������� ��� ������ ����������� �� �����
void displayWordFrequency(const map<string, int>& wordFrequency);

// ������� ��� ������ ����������� � ����
void writeWordFrequencyToFile(const map<string, int>& wordFrequency, const string& outputFilePath);

// ������� ��� �������� ���������� �� �����
string removePunctuation(const string& word);

// �������� ������� ��� �������� ����������� ����
void countWordFrequency(const string& inFileName, const string& outFileName);