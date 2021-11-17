// Longest Common Subsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
int Longest_Common_Subsequence(string text1, string text2) {
    vector<vector<int>> dptable(text1.size()+1, vector<int>(text2.size()+1,0));
    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dptable[i][j] = dptable[i - 1][j - 1] + 1;
            }
            else {
                dptable[i][j] = max(dptable[i - 1][j], dptable[i][j - 1]);//up cell and left cell
            }
        }
    }
    return dptable[text1.size()][text2.size()];
}

int main()
{
    string text1 = "abcd";
    string text2 = "acbd";
    cout << Longest_Common_Subsequence(text1, text2) << endl;
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
