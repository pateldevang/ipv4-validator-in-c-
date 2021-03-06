// ipv4 validator c++ implementation

// MARK: - Headers
#include <iostream>
#include <string.h>
using namespace std;


// MARK: - Error function
void error(int a)
{
    cout<<"The IP is invalid-"<<a;
    exit(1);
}

// MARK: - Sum function
int sum(int s1,int s2,int s3,int co)
{
    int sum=0;
    if(co==1)
    {
        sum=s1;
    }
    else if(co==2)
    {
        sum=s2+s1*10;
    }
    else
    {
        sum=s1*100+s2*10+s3;
    }
    return sum;
}

// MARK: - Check range function (0 to 255)
void checkRange(int tm)
{
    if (!(tm>=0 && tm<=255))
    {
        // Error type 1
        error(1);
    }
}

// MARK: - Main function

int main()

{
    
    // MARK: - Variables and user inputs
    string s;
    int test=0,t1=0;
    cout<<"Enter ipv4 to check : ";
    cin>>s;
    int count=0,a[30],b[30],c[30],d[30],k=0;
    int ca=0,cb=0,cc=0,cd=0;
    int n = s.size();
    
    // Initialise a,b,c,d to 0.
    for(int i=0;i<30;i++)
    {
        a[i]=0;
        b[i]=0;
        c[i]=0;
        d[i]=0;
    }
    
    // MARK: - Function to check bit size is less then three else throw error type 2
    for(int i=0;i<n;i++)
    {
        if (test > 3)
        {
            error(2);
        }
        else if(s[i]=='.')
        {
            count++;
            test=0;
        }
        else
        {
            test++;
        }
    }
    if(count!=3)
    {
        error(2);
    }
    
   
    // MARK: - Function to check preceding zeros if then throw error type 3 and type 4
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.')
        {
            if(t1==2)
            {
                if(s[i-2]=='0')
                {
                    error(3);
                }
            }
            else if(t1==3)
            {
                if((s[i-3]=='0' && s[i-2]=='0') || (s[i-3]=='0' && s[i-2]!='0'))
                {
                    error(4);
                }
            }
            t1=0;
        }
        else
        {
            t1++;
        }
    }
    
   
    int t=0;
    count=0;
    
    // MARK: - Function to get values values of a,b,c,d by adding the 4 parts of the ipv4 and also to get the count of each part i.e ca, cb, cc, cd
    for(int i=0;i<n;i++)
    {
        
        if(s[i]=='.' && count!=3)
        {
            for(int j=t;j<i;j++)
            {
                if (isdigit(s[j]) == 1)
                {
                    if(count==0)
                    {
                        a[k]=(int)s[j]-48;
                        ca++;
                        k++;
                    }
                    else if(count==1)
                    {
                        b[k]=(int)s[j]-48;
                        cb++;
                        k++;
                    }
                    else if(count==2)
                    {
                        c[k]=(int)s[j]-48;
                        cc++;
                        k++;
                    }
                }
                else {
                    error(5);
                }
            }
            t=i+1;
            k=0;
            count++;
        }
        if(count==3)
        {
            k=0;
            // Goto to e
            goto e;
        }
    }

    
    // MARK : - e label for goto
e:
    for(int j=t;j<n;j++)
    {
        if (isdigit(s[j]) == 1)
        {
            d[k]=(int)s[j]-48;
            cd++;
            k++;
        }
        else {
            error(5);
        }
    }
    
    
    
    // MARK: - sum variables
    int sa=0,sb=0,sc=0,sd=0;
    
 
    // Calculate the vaule of sa, sb, sc, sd using sum()
    sa=sum(a[0],a[1],a[2],ca);
    sb=sum(b[0],b[1],b[2],cb);
    sc=sum(c[0],c[1],c[2],cc);
    sd=sum(d[0],d[1],d[2],cd);
    
    // Check range for the above vaules using checkRange()
    checkRange(sa);
    checkRange(sb);
    checkRange(sc);
    checkRange(sd);
    
    // If no error with exit() then print IP is valid
    cout<<"The IP is valid";
    
    return 0;
}
