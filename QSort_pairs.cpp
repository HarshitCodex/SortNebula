#include<bits/stdc++.h>
using namespace std;
/*void swaps(int *a, int *b)
{
    int t= *a;
    *a=*b;
    *b=t;
}*/
int partition(vector <pair<int,int> > &arr,int low,int high)
{
    int pivot = arr[high].first;
    int i=(low-1);
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j].first<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
            //swaps(&(arr[i].first),&(arr[j].first));
            //swaps(&(arr[i].second),&(arr[j].second));
        }
        else if(arr[j].first==pivot)
        {
            if(arr[j].second<arr[high].second)
            {
                i++;
                //swaps(&(arr[i].first),&(arr[j].first));
                //swaps(&(arr[i].second),&(arr[j].second));
                swap(arr[i],arr[j]);
            }
        }
    }

    //swaps(&(arr[i+1].first),&(arr[high].first));
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quicksort(vector<pair<int , int> > &arr,int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }

}
int main()
{
    int n;
    cout<<"Please enter the size of vector ";
    cin>>n;
    vector<pair<int,int> > test;
    cout<<"Please enter your key value pairs one by one "<<endl;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        test.push_back(make_pair(a,b));
    }
    cout<<"\nWe will perform quick sort and sort by value of first\n";
    quicksort(test,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<"("<<test[i].first<<" , "<<test[i].second<<")"<<endl;
    }
    return 0;
}
