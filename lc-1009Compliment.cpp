# include<iostream>
# include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int num=0;
        int i=0;
        if(n==0)
        return 1;
        while(n!=0){
            int a=(n&1);
            if(a==0)
                num=num+pow(2,i);
            i++;
            n=n>>1;
        }
        cout<<num;
}    