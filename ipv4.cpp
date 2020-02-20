#include <iostream>
#include <string.h>
using namespace std;



void error(int a)
{
	cout<<"The IP is invalid-"<<a;
	exit(1);
}

int main()

{
	string s;
	cin>>s;
	int count=0,a[3],b[3],c[3],d[3],k=0;
	int n = s.size();
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
						a[k]=(int)s[j];
						//cout<<(int)s[j]-48;
						k++;
					}
					else if(count==1)
					{
						b[k]=(int)s[j];
						//cout<<(int)s[j]-48;
						k++;
					}
					else if(count==2)
					{
						c[k]=(int)s[j];
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
					d[k]=(int)s[j];
					//cout<<(int)s[j]-48;
					k++;
				}
				else {
					error(3);
				}
		}
		
		
	cout<<"The IP is valid";
		
		//cout<<a[0];
	
	return 0;
}



