#include<bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the row/col in matrix"<<endl;
    int n;
    cin>>n;
   
    vector<vector<int>>matrix(n, vector<int>(n));
    
    cout<<"Enter the D0 Matrix"<<endl;
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin >> temp;
            if(temp == 99999)
                matrix[i][j] = INT_MAX;
            else
                matrix[i][j] = temp;
        }
        
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++ ){
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (matrix[i][j] == INT_MAX)
            cout << "INF ";
        else
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;

}


// Enter the row/col in matrix
// 6
// 6
// Enter the D0 Matrix
// 0 99999 99999 99999 -1 99999
// -4 0 99999 99999 3 99999
// 99999 99999 0 2 99999 -6
// 1 2 99999 0 99999 99999
// 99999 99999 99999 7 0 99999
// 99999 99999 10 5 99999 0
// 0 8 INF 6 -1 INF
// -4 0 INF 2 -5 INF
// -3 1 0 -1 -4 -6
// -2 2 INF 0 -3 INF
// 5 9 INF 7 0 INF
// 3 7 10 5 2 0
