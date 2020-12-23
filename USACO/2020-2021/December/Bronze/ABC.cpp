//Done for the memes

#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[7];
  for(int i=0; i<7; i++){
    cin>>arr[i];
  }
  sort(arr, arr+7);
  int ans[3]={0};
  for(int i=0; i<7; i++){
    for(int j= 0; j<7; j++){
      if(i!=j){
        for(int k = 0; k<7; k++){
          if(!(k==j||k==i)){
            for(int l=0; l<7; l++){
              if(!(l==k||l==j||l==i)){
                for(int m=0; m<7; m++){
                  if(!(m==l||m==k||m==j||m==i)){
                    for(int n=0; n<7; n++){
                      if(!(n==m||n==l||n==k||n==j||n==i)){
                        for(int o=0; o<7; o++){
                          if(!(o==n||o==m||o==l||o==k||o==j||o==i)){
                            int abc = arr[o];
                            int bc = arr[n];
                            int ac = arr[m];
                            int ab = arr[l];
                            int c = arr[k];
                            int b = arr[j];
                            int a = arr[i];
                            if(a+b==ab&&a+c==ac&&b+c==bc&&a+b+c==abc){
                              ans[0] = a;
                              ans[1] = b;
                              ans[2] = c;
                            }
                          }
                        }
                      } 
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  sort(ans, ans+3);
  cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
}
