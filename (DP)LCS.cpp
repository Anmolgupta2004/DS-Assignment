#include<bits/stdc++.h>
using namespace std;

pair<vector<vector<int>>,vector<vector<char>>> LCS(string str1, string str2) {
    int str1len = str1.length();
    int str2len = str2.length();
    
 
vector<vector<int>> number(str1len + 1, vector<int>(str2len + 1, 0));
vector<vector<char>> anmol(str1len + 1, vector<char>(str2len + 1, ' '));

    for (int i = 1; i <= str1len; i++) {
        for (int j = 1; j <= str2len; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                number[i][j] = number[i - 1][j - 1] + 1;
                anmol[i][j]='d';
                
            } else {
                if(number[i-1][j]>=number[i][j-1]){
                    number[i][j]=number[i-1][j];
                    anmol[i][j]='u';
                }else{
                    number[i][j]=number[i][j-1];
                    anmol[i][j]='r';
                }
            }
                
        }
    }
    return {number,anmol}; 
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    
 pair<vector<vector<int>>, vector<vector<char>>> ans = LCS(str1, str2);
  vector<vector<int>> number = ans.first;
    vector<vector<char>> anmol = ans.second;

    
    cout << "LCS Length-Direction Table:" << endl;

    for (int i = 0; i <= str1.length(); i++) {
        for (int j = 0; j <= str2.length(); j++) {
            cout<<number[i][j]<<anmol[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}


// ABCBDAB
// BDCABA
// LCS Length Table:
// Direction Table :
// 0  0  0  0  0  0  0  
// 0  0u 0u 0u 1d 1r 1d 
// 0  1d 1r 1r 1u 2d 2r 
// 0  1u 1u 2d 2r 2u 2u 
// 0  1d 1u 2u 2u 3d 3r 
// 0  1u 2d 2u 2u 3u 3u 
// 0  1u 2u 2u 3d 3u 4d 
// 0  1d 2u 2u 3u 4d 4u 
