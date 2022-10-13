#include<iostream>
using namespace std;
int main(){

    //Check last bit using bitwise and then right shift n
        uint32_t n=0111;
           int cnt=0;
        while(n!=0){
            if((n&1)==1)
            cnt++;
            n=n>>1;
        }
        cout<< cnt;
}
     