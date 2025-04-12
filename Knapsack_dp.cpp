#include <bits/stdc++.h>

using namespace std;
int main(){
    int items, capacity;
    cout << "Enter number of items: ";
    cin >> items;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    vector<int> weights(items), values(items);
    cout << "Enter weights of items: ";
    for(int i = 0; i < items; i++){
        cin >> weights[i];
    }
    cout << "Enter values of items: ";
    for(int i = 0; i < items; i++){
        cin >> values[i];
    }
    vector<vector<int>> ans(items+1, vector<int>(capacity+1,0));

    for(int i=1;i<=items;i++){
        for(int w=1;w<=capacity;w++){
            if(weights[i-1]<=w){
                ans[i][w] = max( values[i - 1] + ans[i - 1][w - weights[i - 1]],ans[i - 1][w]);

            }else{
                ans[i][w] = ans[i - 1][w];
            }
        }
    }

    cout << "Dynamic Programming Table:" << endl;
    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Maximum value in knapsack = " << ans[items][capacity] << endl;
  
    

    
    
    return 0;
}



// ex:--
//   Enter number of items: 7
// Enter capacity of knapsack: 15
// Enter weights of items: 2
// 3
// 5
// 7
// 1
// 4
// 1
// Enter values of items: 10
// 5
// 15
// 7
// 6
// 18
// 3
// Dynamic Programming Table:
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 0 0 10 10 10 10 10 10 10 10 10 10 10 10 10 10
// 0 0 10 10 10 15 15 15 15 15 15 15 15 15 15 15
// 0 0 10 10 10 15 15 25 25 25 30 30 30 30 30 30
// 0 0 10 10 10 15 15 25 25 25 30 30 30 30 32 32
// 0 6 10 16 16 16 21 25 31 31 31 36 36 36 36 38
// 0 6 10 16 18 24 28 34 34 34 39 43 49 49 49 54
// 0 6 10 16 19 24 28 34 37 37 39 43 49 52 52 54
// Maximum value in knapsack = 54
