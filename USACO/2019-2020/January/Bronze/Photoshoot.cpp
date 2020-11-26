#include <fstream>
using namespace std;
ifstream fin("photo.in");
ofstream fout("photo.out");

int main() {
  int n;
  fin>>n;
  int arr[n-1];
  for(int i=0; i<n-1;i++)
    fin>>arr[i];
  int ans[n];
  bool completed =false;
  for(int start=1; n; start++){
    int x =start;
    ans[0] = start;
    bool visited[1000]={false};
    for(int i=0; i<n-1;i++){
      int out = arr[i]-x;
      if(visited[out]==true||out<=0||out>1000)
      {
        break;
      }
      else if(i==n-2&&visited[out]==false)
      {
       completed=true;
       ans[i+1]=out;
       break;
      }
      else{
        visited[out] = true;
        ans[i+1]=out;
        x=out;
      }
    }
    if(completed==true) break;
  }
  fout<<ans[0];
  for(int i=1; i<n; i++)
    fout<<" "<<ans[i];
}
