#include<iostream>
#include<vector>
using namespace std;
#define s 1000000


vector<int> primeSeive()
{
    vector<int> seive;
    seive.resize(s);

    seive[2]=1;
    for(int i=3;i<s;i+=2)
    {
        seive[i]=1;
    }

    for(int i=3;i*i<s;i+=2)
    {
        if(seive[i])
        {
            for(int j=i*i;j<s;j+=i)
            {
                seive[j]=0;
            }
        }
    }

    for(int i=1;i<s;i++)
    {
        seive[i]+=seive[i-1];
    }
    return seive;
}

int main() {
    int t;
    cin>>t;
    vector<int> p=primeSeive();
    //vector p has count of prime nos less than or equal to any p[i]
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<p[b]-p[a-1]<<endl;
    }
    return 0;
}