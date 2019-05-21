#include<bits/stdc++.h>
using namespace std;
void merge(vector<pair<int,int> > &arr,int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    vector<pair<int , int> > L,R;
    for( i=0;i<n1;i++)
    {
        L.push_back(make_pair(arr[l+i].first,arr[l+i].second));
    }
    for( j=0;j<n2;j++)
    {
        R.push_back(make_pair(arr[m+1+j].first,arr[m+1+j].second));
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i].first < R[j].first || ((L[i].first == R[j].first)&&(L[i].second <= R[j].second)))
        {
            arr[k].first=L[i].first;
            arr[k].second=L[i].second;
            i++;
        }
        {
            arr[k].first=R[i].first;
            arr[k].second=R[i].second;
            j++;
        }
        k++;
    }
    while(i<n1)
    {
            arr[k].first=L[i].first;
            arr[k].second=L[i].second;
            i++;
            k++;
    }
    while(j<n2)
    {
            arr[k].first=R[i].first;
            arr[k].second=R[i].second;
            j++;
            k++;
    }
}
void mergeSort(vector<pair<int,int> > &arr,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        //Now i have merged them both

        merge(arr,l,m,r);
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
    cout<<"\nWe will perform quick sort and sort by value of first\n";
    mergeSort(test,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<"("<<test[i].first<<" , "<<test[i].second<<")"<<endl;
    }
    return 0;
}
