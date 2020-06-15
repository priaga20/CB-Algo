#include <iostream>
#include<string>
#include<vector>
using namespace std;

string getString(char d)
{
    if(d=='1') return "abc";
    if(d=='2') return "def";
    if(d=='3') return "ghi";
    if(d=='4') return "jkl";
    if(d=='5') return "mno";
    if(d=='6') return "pqrs";
    if(d=='7') return "tuv";
    if(d=='8') return "wx";
    if(d=='9') return "yz";
    return "";
}
    
vector<string> getCombinations(string digits,int s,vector<string> output)
{
    //base case
    if(s==digits.size())  
    {
        output.push_back("");
        return output;
    }

    //hypothesis
    vector<string> smallOutput=getCombinations(digits,s+1,output);

    //small calculation
    string c=getString(digits[s]);
    for(int i=0;i<c.size();i++)
    {
        for(int j=0;j<smallOutput.size();j++)
        {
            output.push_back(c[i]+smallOutput[j]);
        }
    }
    return output;
}

void printCombinations(vector<string> output,int s)
{
    if(s==output.size())
        return;
    cout<<output[s]<<" ";
    printCombinations(output,s+1);
}

int countCombinations(vector<string> output,int s)
{
    if(s==output.size())
        return 0;
    return 1+countCombinations(output,s+1);
}

int main() {

    string digits;
    cin>>digits;

    vector<string> ans;
    ans=getCombinations(digits,0,ans);

    printCombinations(ans,0);
    cout<<endl;
    int n=countCombinations(ans,0);
    cout<<n;
}
