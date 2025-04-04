
// #include<vector>
// #include<map>
// #include<algorithms>
#include<bits/stdc++.h>
// #include<algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter total number of items "<<endl;
    cin >> n;

    vector<vector<int>> items(n,vector<int>(2));

    for(int i=0; i<n; i++)
    {
        int w,v;
        cout << "Enter weight of "<< i+1<<"th item   ";
        cin >> w;
        cout << "Enter value : ";
        cin >> v;

        items[i] = {w,v};
    }
         int W;
        cout << "Enter total Weight capacity"<<endl;
        cin >> W;

     vector<vector<int>> pricePerUnitWeight(n);

    for(int i=0; i<n; i++)
     {
        int unitPrice = items[i][1]/items[i][0];
           pricePerUnitWeight[i] = {unitPrice,items[i][0]};
     }

     sort(pricePerUnitWeight.rbegin(),pricePerUnitWeight.rend());


      int ansValue = 0 , ansWeight = 0;

       for(int i=0; i<n && ansWeight < W; i++)
       {
         int rem;
         if((W - ansWeight) < pricePerUnitWeight[i][1])
         rem = W - ansWeight;
         else
         rem = pricePerUnitWeight[i][1];

         int curr = pricePerUnitWeight[i][0]*rem;
         if(curr >= 0)
         {
             ansValue += curr;
            ansWeight += rem;
         }
       }

       cout <<" Maximum Amount is : "<<ansValue<<endl;
       cout << "Maximum occupied weight is : "<<ansWeight<<endl;


    return 0;
}
