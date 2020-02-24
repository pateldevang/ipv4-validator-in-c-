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
	int test=0;
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
	
    // MARK: - Function to check bit size
	for(int i=0;i<n;i++)
	{
		if (test > 3)
		{
			error(6);
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
	int t1=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.')
		{
			
			if(t1==2)
			{
				if(s[i-2]=='0')
				{
					error(9);
				}
			}
			else if(t1==3)
			{
				if(s[i-3]=='0' && s[i-2]=='0')
				{
					error(10);
				}
			}
			t1=0;
			
		}	
		else
		{
			t1++;
		}
	}
	
	if(count!=3)
	{
		error(1);
	}
	int t=0;
	count=0;
	for(int i=0;i<n;i++)
	{
		
		if(s[i]=='.' && count!=3)
		{
			for(int j=t;j<i;j++)
			{
				if (isdigit(s[j]) == 1)
				{
					//cout<<s[j];
					if(count==0)
					{
						a[k]=(int)s[j]-48;
						ca++;
						//cout<<(int)s[j]-48;
						k++;
					}
					else if(count==1)
					{
						b[k]=(int)s[j]-48;
						cb++;
						//cout<<(int)s[j]-48;
						k++;
					}
					else if(count==2)
					{
						c[k]=(int)s[j]-48;
						cc++;
						//cout<<(int)s[j]-48;
						k++;
					}
				}
				else {
					error(2);
				}
			}
			t=i+1;
			k=0;
			count++; 
		}
		if(count==3)
		{
			k=0;
			goto e;
		}
		
	}
	
	e:
	for(int j=t;j<n;j++)
		{
			if (isdigit(s[j]) == 1)
				{
					d[k]=(int)s[j]-48;
					cd++;
					//cout<<(int)s[j]-48;
					k++;
				}
				else {
					error(3);
				}
		}
		
		//cout<<a[0]<<" "<<a[1]<<" "<<a[2];
	
		
		int sa=0,sb=0,sc=0,sd=0;
		
		if(ca==1)
		{
			sa=a[0];
		}
		else if(ca==2)
		{
			sa=a[1]+a[0]*10;
		}
		else 
		{
			sa=a[0]*100+a[1]*10+a[2];
		}
		
		if(cb==1)
		{
			sb=b[0];
		}
		else if(cb==2)
		{
			sb=b[1]+b[0]*10;
		}
		else 
		{
			sb=b[0]*100+b[1]*10+b[2];
		}
		
		if(cc==1)
		{
			sc=c[0];
		}
		else if(cc==2)
		{
			sc=c[1]+c[0]*10;
		}
		else 
		{
			sc=c[0]*100+c[1]*10+c[2];
		}
		
		if(cd==1)
		{
			sd=d[0];
		}
		else if(cd==2)
		{
			sd=d[1]+d[0]*10;
		}
		else 
		{
			sd=d[0]*100+d[1]*10+d[2];
		}
		
		sa=sum(a[0],a[1],a[2],ca);
		sb=sum(b[0],b[1],b[2],cb);
		sc=sum(c[0],c[1],c[2],cc);
		sd=sum(d[0],d[1],d[2],cd);
		
		checkRange(sa);
		checkRange(sb);
		checkRange(sc);
		checkRange(sd);
				
		cout<<"The IP is valid";
		

	
	return 0;
}



