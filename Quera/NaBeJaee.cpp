#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, arr[maxn], tmp[maxn];

long long int swaps(int start, int end){
    if(start == end)
        return 0;
    int mid = (start + end) / 2;
    long long int cnt = swaps(start, mid) + swaps(mid+1, end);
    int lptr = start, rptr = mid+1;
    int output = start;
    while(lptr <= mid || rptr <= end){
        if(lptr == mid+1)
            tmp[output++] = arr[rptr++];
        else if(rptr == end+1)
            tmp[output++] = arr[lptr++];
        else{
            if(arr[lptr] > arr[rptr]){
                tmp[output++] = arr[rptr++];
                cnt += mid - lptr + 1;
            }
            else tmp[output++] = arr[lptr++];
        }
    }
    copy(tmp+start, tmp+output, arr+start);
    return cnt;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << swaps(0, n-1) << endl;
}