#include<iostream>
#include<vector>
using namespace std;

void solve(int i, vector<int>& arr, int rem_sum, vector<vector<int>>& ans, vector<int>& curr, int n)
{
    if(i >= n || rem_sum <= 0)
    {
        if(rem_sum == 0)
        ans.push_back(curr);

        return ;
    }

     solve(i+1,arr,rem_sum,ans,curr,n);
      curr.push_back(arr[i]);
      rem_sum -= arr[i];
      solve(i+1,arr,rem_sum,ans,curr,n);

      curr.pop_back();
      return ;
}

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of an array \n";

    for(int i=0; i<n; i++)
     cin >> arr[i];

    int target_sum ;

     cout << "Enter the target sum : ";
      cin >> target_sum;

      vector<vector<int>> ans;

      vector<int> curr;

      solve(0,arr,target_sum,ans,curr,n);

      cout << "Possible solutions are : " << endl;

      for(int i=0; i<ans.size(); i++)
      {
        for(auto j : ans[i])
         cout << j << " ";
         cout << endl;
      }


    return 0;
}
