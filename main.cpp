#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <Windows.h>

#include "functions.h"  // ������������ ���� � ���������

using namespace std;

int main() 
{
    // ������������� ������� ���� � �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputFilePath = "input.txt";    // ���� � ����� ��� ������
    string outputFilePath = "output.txt";  // ���� � ����� ��� ������ �����������

    // �������� �������� ������� ��� �������� ����������� ����
    countWordFrequency(inputFilePath, outputFilePath);

    return 0;
}