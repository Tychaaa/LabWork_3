#include "functions.h"

// ������� ��� ������ ����������� �� �����
void displayWordFrequency(const map<string, int>& wordFrequency)
{
    // �������� �� ���� ����� ����-�������� � map
    for (const auto& pair : wordFrequency)
    {
        // ����� ����� (�����) � �������� (�������), ����������� ����������
        cout << pair.first << ": " << pair.second << endl;
    }
}

// ������� ��� ������ ����������� � ����
void writeWordFrequencyToFile(const map<string, int>& wordFrequency, const string& outputFilePath)
{
    // ��������� ���� ��� ������
    ofstream outFile(outputFilePath);

    // ���������, ������� �� ������� ����
    if (!outFile.is_open())
    {
        // ���� �� ������� ������� ����, ������� ��������� �� ������ � ������� �� �������
        cerr << "�� ������� ������� ���� " << outputFilePath << endl;
        return;
    }

    // ��������� �� ���� ����� ����-�������� � map
    for (const auto& pair : wordFrequency)
    {
        // ���������� � ���� ���� (�����) � �������� (�������), ����������� ����������
        outFile << pair.first << ": " << pair.second << endl;
    }

    // ��������� ����
    outFile.close();
}

// ������� ��� �������� ���������� �� �����
string removePunctuation(const string& word)
{
    string result;  // ������ ��� �������� ���������� ��� ����������

    // ����������� �������� �� word � result, ���� ��� �� �������� �����������
    copy_if(word.begin(), word.end(), back_inserter(result),
        [](char c)  // ������-������� ��� �������� ��� copy_if
        {
            // ���������� ���� char � unsigned char ��� ���������� ������ ispunct
            // � ������� true, ���� ������ �� �������� �����������
            return !ispunct(static_cast<unsigned char>(c));
        });

    return result;  // ������� ����� ������ ��� ����������
}

// �������� ������� ��� �������� ����������� ����
void countWordFrequency(const string& inFileName, const string& outFileName)
{
    // ��������� ���� ��� ������
    ifstream file(inFileName);

    map<string, int> wordCount; // ������� ��� �������� ���� � �� ������

    // ���������, ������� �� ������� ����
    if (!file.is_open())
    {
        // ���� �� ������� ������� ����, ������� ��������� �� ������ � ������� �� �������
        cerr << "�� ������� ������� ����!" << endl;
        return;
    }

    string word;    // ������ ��� �������� ������� �����, ������������ �� �����

    // ������ ����� ����� �� ������
    while (file >> word)
    {
        // �������� ���������� �� ����
        word = removePunctuation(word);
        // ������������� ����� � ������� ��������
        transform(word.begin(), word.end(), word.begin(), tolower);

        // ���� ����� � �������, ���� ��� �� ������
        if (!word.empty())
        {
            wordCount[word]++; // ��������� ������� �����
        }
    }

    // ����� ������� ���� �� �����
    displayWordFrequency(wordCount);
    // ������ ������� ���� � ����
    writeWordFrequencyToFile(wordCount, outFileName);

    // �������� �����
    file.close();
}