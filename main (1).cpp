/******************************************************************************
 Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.
activity selection problem
logic : starting time of second > ending time of first
*******************************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Meeting
{
    int start,finish,n;
};
static bool comp(Meeting a,Meeting b)
{
    return a.finish<b.finish;
}
void maxmeeting(int start[],int finish[],int n)
{
    vector<Meeting>meetings;
    for(int i=0;i<n;i++)
    {
         Meeting m;
    m.start=start[i];
    m.finish=finish[i];
    m.n=i+1;
    meetings.push_back(m);
    }
    sort(meetings.begin(),meetings.end(),comp);
    
    vector<int>store;
    store.push_back(meetings[0].n);
    int finishtime=meetings[0].finish;
    for(int i=1;i<n;i++)
    {
        if(meetings[i].start>=finishtime)
        {
            store.push_back(meetings[i].start);
            finishtime=meetings[i].finish;
        }
    }
    cout<<"total number of meetings"<<store.size()<<endl;
    cout<<"meeting number";
    for(int meeting : store)
    {
        cout<<meeting<<" ";
    }
    
}
int main()
{
    int tc;
    cout<<"enter number of test cases"<<endl;
    cin>>tc;
    while(tc--)
    {
        int n;
        cout<<"enter number of meetings";
        cin>>n;
        int start[n];
        int finish[n];
        cout<<"enter starting time";
        for(int i=0;i<n;i++)
        {
            cin>>start[i];
        }
        cout<<"enter finish time";
        for(int i=0;i<n;i++)
        {
            cin>>finish[i];
        }
        maxmeeting(start,finish,n);
    }
}
