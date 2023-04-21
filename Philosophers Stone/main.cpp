#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int w,h;
        cin >> h >> w;
        vector<vector<int>> arr(h,vector<int>(w));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> arr[i][j];
            }
        }
        for(int i=1; i<h; i++){
            for(int j=0; j<w; j++){
                int temp;
                if(j==0){
                    arr[i][j] += max(arr[i-1][j],arr[i-1][j+1]);
                }
                else if(j==w-1){
                    arr[i][j] += max(arr[i-1][j],arr[i-1][j-1]);
                }
                else{
                    arr[i][j] += max(arr[i-1][j],max(arr[i-1][j-1],arr[i-1][j+1]));
                }
            }
        }
        int result = INT32_MIN;
        for (int i = 0; i < w; i++)
        {
            result = max(result,arr[h-1][i]);
        }
        cout << result << endl;
    }
    return 0;
}