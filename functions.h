#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <Windows.h>

using namespace std;

// Функция для вывода результатов на экран
void displayWordFrequency(const map<string, int>& wordFrequency);

// Функция для записи результатов в файл
void writeWordFrequencyToFile(const map<string, int>& wordFrequency, const string& outputFilePath);

// Функция для удаления пунктуации из слова
string removePunctuation(const string& word);

// Основная функция для подсчета частотности слов
void countWordFrequency(const string& inFileName, const string& outFileName);