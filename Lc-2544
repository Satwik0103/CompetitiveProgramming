class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> v;
        int ans=0;
        //storing n in vector v
        while(n>0)
        {
            v.push_back(n%10);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        //adding values at even indices and subtracting at odd indices.
        for(int i=0; i<v.size();i++)
        {
            if(i%2==0)
                ans+=v[i];
            else
                ans-=v[i];
        }
        return ans;
    }
};
