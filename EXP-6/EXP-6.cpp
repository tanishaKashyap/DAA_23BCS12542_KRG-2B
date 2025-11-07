#include <iostream> 
#include <vector> 
using namespace std; 
 
bool subsetSum(vector<int>& arr, int sum) {   
      int n = arr.size();    
       vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false)); 
 
    
      for(int i=0; i<=n; i++)       
        dp[i][0] = true; 
 
      
     for(int i=1; i<=n; i++) {      
           for(int j=1; j<=sum; j++) {         
                if(arr[i-1] <= j)               
                  dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];          
                     else           
                           dp[i][j] = dp[i-1][j]; 
        } 

    } 
    return dp[n][sum]; 
} 
 
int main() {     int n, sum;  
       cout << "Enter number of elements: "; 
    cin >> n; 
 
    vector<int> arr(n);  
       cout << "Enter elements: "; 
    for(int i=0; i<n; i++) 
    cin >> arr[i]; 
 
    cout << "Enter target sum: ";    
     cin >> sum; 
 
    if(subsetSum(arr, sum)) 
        cout << "Subset with given sum exists!" << endl;  
           else        
            cout << "No subset with given sum exists!" << endl; 
 
    return 0; 
}
