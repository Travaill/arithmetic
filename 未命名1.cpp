         #include<stdlib.h>  
#include<iostream>  
using namespace std;  
int main()  
{  
    int n;  
    cin>>n;  
    int a[100001];  
    int i,j;  
    int zero_pos[100];  
    int num=0;  
    int flag=0;  
    for(i=1;i<=n;i++)  
    {  
        cin>>a[i];  
        if(a[i]==0)  
        {  
            zero_pos[num]=i;  
            num++;  
            flag=1;  
        }  
    }  
    if(flag==0) cout<<"Yes";  
    else  
    {  
        int fla;
        for(i=0;i<num;i++)  
        {  
            
		   fla=0;  
           for(j=zero_pos[i];j>=1;j--)  
          {  
            if(a[j]<=zero_pos[i]-j)  
            {  
              break;  
            }    
              if(a[j]>zero_pos[i]-j)  
            {  
                fla++;  
               break;  
            }  
          }  
          if(j>0) continue;  
          if(j==0) break;  
        }  
        if (fla==num) cout<<"Yes";  
        else cout<<"No";  
    }  
}  
