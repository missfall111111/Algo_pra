#include<iostream>

using namespace std;

int ifawin(int a,int b)
{
    if(a==b)
    {
        return 0;
    }
    if(a==0 && b==1)
    {
        return -1;
    }
    if(a==0 && b==2)
    {
        return 1;
    }
    if(a==0 && b==3)
    {
        return 1;
    }
    if(a==0 && b==4)
    {
        return -1;
    }
    if(a==1 && b==2)
    {
        return -1;
    }
    if(a==1 && b==3)
    {
        return 1;
    }
    if(a==1 && b==4)
    {
        return -1;
    }
    if(a==2 && b==3)
    {
        return -1;
    }
    if(a==2 && b==4)
    {
        return 1;
    }
    if(a==3 && b==4)
    {
        return 1;
    }

    return -ifawin(b,a);
}
int main()
{
    int times,x,y;
    cin>>times>>x>>y;
    int a[x],b[y];
    for(int i=0;i<x;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<y;i++)
    {
        cin>>b[i];
    }
    int sa=0,sb=0;
    int pa=0,pb=0;

    for(int i=0;i<times;i++)
    {
        if(ifawin(a[pa],b[pb])==1)
        {
            sa++;
        }
        else if(ifawin(a[pa],b[pb])==-1)
        {
            sb++;
        }
        pa=(pa+1)%x;
        pb=(pb+1)%y;
    }
    cout<<sa<<" "<<sb<<endl;
}