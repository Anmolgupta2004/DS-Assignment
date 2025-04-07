#include<bits/stdc++.h>

using namespace std;

void print_lcs(vector<vector<char>>&anmol,string str1,int i,int j,string &str){
    //string str="";
    if(i==0 ||j==0){
        return ;
    }
    if(anmol[i][j]=='d'){
        print_lcs(anmol,str1,i-1,j-1,str);
        str += str1[i-1];
    }else if(anmol[i][j]=='u'){
        print_lcs(anmol,str1,i-1,j,str);

    }else{
        print_lcs(anmol,str1,i,j-1,str);
    }
}

pair<vector<vector<int>>,vector<vector<char>>>LCS(string str1,string str2){

    int str1len=str1.length();
    int str2len=str2.length();

    vector<vector<int>>number(str1len+1,vector<int>(str2len+1,0));
    vector<vector<char>>anmol(str1len+1,vector<char>(str2len+1,' '));

    for(int i=1;i<str1len+1;i++){
        for(int j=1;j<str2len+1;j++){
            if(str1[i-1]==str2[j-1]){
                number[i][j]=number[i-1][j-1]+1;
                anmol[i][j]='d';
            }else{
                if(number[i-1][j]>=number[i][j-1]){
                    number[i][j]=number[i][j-1];
                    anmol[i][j]='u';
                }else{
                    number[i][j]=number[i][j-1];
                    anmol[i][j]='r';
                }

            }
        }

    }
    return { number,anmol};
}

int main(){
string str1,str2;
cin>>str1>>str2;

pair<vector<vector<int>>,vector<vector<char>>> ans=LCS(str1,str2);

vector<vector<int>>number=ans.first;
vector<vector<char>>anmol=ans.second;

for(int i=0;i<anmol.size();i++){
for(int j=0;j<anmol[0].size();j++){
    cout<<anmol[i][j]<<  "  ";
}
cout<<endl;
}


string str="";
int i=anmol.size();
int j=anmol[0].size();

print_lcs(anmol,str1,i-1,j-1,str);
cout << "ijkdfhhgb     " <<str;
// cout<<<<endl;


    return 0;
}
