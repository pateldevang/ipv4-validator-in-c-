#include <iostream>
#include <string.h>
using namespace std;



void error(int a)
{
	cout<<"The IP is invalid-"<<a;
	exit(1);
}

void checkRange(int tm)
{
	cout<<tm;
	if (!(tm>=0 && tm<=255))
	{
		error(4);
	}
}

int main()

{
	string s;
	cin>>s;
	int count=0,a[30],b[30],c[30],d[30],k=0;
	int n = s.size();
	
	for(int i=0;i<30;i++)
	{
		a[i]=0;
		b[i]=0;
		c[i]=0;
		d[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.')
		{
			count++;
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
						//cout<<(int)s[j]-48;
						k++;
					}
					else if(count==1)
					{
						b[k]=(int)s[j]-48;
						//cout<<(int)s[j]-48;
						k++;
					}
					else if(count==2)
					{
						c[k]=(int)s[j]-48;
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
					//cout<<(int)s[j]-48;
					k++;
				}
				else {
					error(3);
				}
		}
		
		//int temp=0;
		//for(int j=0;j<30;j++)
		//	{
		//		temp=a[0]
		//	}
			
			//checkRange(temp);
			
				
		cout<<"The IP is valid";
		
		//cout<<a[0];
	
	return 0;
}
