#include <bits/stdc++.h>
using namespace std;

void printOptimalParenthesization(vector<vector<int>>& k_matrix, int i, int j, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printOptimalParenthesization(k_matrix, i, k_matrix[i][j], name);
    printOptimalParenthesization(k_matrix, k_matrix[i][j] + 1, j, name);
    cout << ")";
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> input(n + 1);
    cout << "Enter the dimensions of matrices (n+1 values): ";
    for (int i = 0; i <= n; i++) {
        cin >> input[i];
    }

    vector<vector<int>> main_matrix(n, vector<int>(n, 0));
    vector<vector<int>> k_matrix(n, vector<int>(n, 0));

    
    for (int l = 2; l <= n; l++) {  
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            main_matrix[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = main_matrix[i][k] + main_matrix[k + 1][j] + input[i] * input[k + 1] * input[j + 1];
                if (q < main_matrix[i][j]) {
                    main_matrix[i][j] = q;
                    k_matrix[i][j] = k;
                }
            }
        }
    }

    
    cout << "Minimum number of multiplications is " << main_matrix[0][n - 1] << endl;

    
    cout << "Optimal Parenthesization: ";
    char name = 'A';
    printOptimalParenthesization(k_matrix, 0, n - 1, name);
    cout << endl;

    
    cout << "Dynamic Programming Table (Cost Matrix):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << main_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
