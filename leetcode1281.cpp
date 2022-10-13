 #include<iostream>
 using namespace std;
 int main(){
    int n=234;
 int sum=0,pro=1,a;
        while(n>0){
            a=n%10;
            cout<<a<<endl;
            sum+=a;
            pro*=a;
            n=n/10;
        }
        int dif=pro-sum;
        cout<<sum<<pro<<dif;
        //return dif;
 }