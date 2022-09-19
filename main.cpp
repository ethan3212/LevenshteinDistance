#include <vector>
#include <iostream>

using namespace std;

int levenshteinDistance(string str1, string str2) {
    // str1 = abc
    //str2 = yabd

    // create our matrix
    vector<vector<int>> edits(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    for(int row = 0; row < edits.size(); row++) {
        for(int col = 0; col < edits[0].size(); col++) {
            edits[row][col] = col;
        }
        edits[row][0] = row;
    }
    //    '' y  a  b  c
    // '' 0  1  2  3  4
    // a  1
    // b  2
    // c  3

    for(int row = 1; row < edits.size(); row++) {
        for(int col = 1; col < edits[0].size(); col++) {
            if(str1[row - 1] == str2[col - 1]) {
                edits[row][col] = edits[row - 1][col - 1];
            } else {
                edits[row][col] = 1 + min(edits[row - 1][col - 1], min(edits[row - 1][col], edits[row][col-1]));
            }
        }
    }

    // this is the populated matrix
    //    '' y  a  b  d
    // '' 0  1  2  3  4
    // a  1  1  1  2  3
    // b  2  2  2  1  2
    // c  3  3  3  2  2 <-- return the value in this cell

    return edits[edits.size() - 1][edits[0].size() - 1];
}

int main() {
    string str1 = "abc";
    string str2 = "yabd";
    cout << levenshteinDistance(str1, str2);
    return 0;
}