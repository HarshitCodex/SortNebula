#include<bits/stdc++.h>
using namespace std;
int getMax(vector<pair<int,int> > &arr,int n)
{
    int mx=arr[0].first;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first>mx)
            mx=arr[i].first;
    }
    return mx;
}
void countsort(vector<pair<int,int> > &arr,int n, int exp)
{
    int output[n];
    int outputz[n];
    int i, count[10]={0};
    for(int i=0;i<n;i++)
    {
        count[(arr[i].first/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[count[(arr[i].first/exp)%10]-1] = arr[i].first;
        outputz[count[(arr[i].first/exp)%10]-1]=arr[i].second;
        count[(arr[i].first/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i].first=output[i];
        arr[i].second=outputz[i];
    }
}
void radixsort(vector<pair<int , int> > &arr,int n)
{
    int m = getMax(arr,n);
    //counting sort for every digit
    for(int e=1;m/e >0;e*=10)
    {
        countsort(arr,n,e);
    }
}
int main()
{
    int n;
    cout<<"Please enter the size of vector ";
    cin>>n;
    vector<pair<int,int> > test;
    cout<<"Please  enter your key value pairs one by one "<<endl;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        test.push_back(make_pair(a,b));
    }
    cout<<"\nWe will perform radix sort and sort by value of first\n";
    radixsort(test,n);
    for(int i=0;i<n;i++)
    {
        cout<<"("<<test[i].first<<" , "<<test[i].second<<")"<<endl;
    }
    return 0;
}
