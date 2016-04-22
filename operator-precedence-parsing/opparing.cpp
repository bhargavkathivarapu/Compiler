#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;
string op[10][10];
string array[30][30];
int tn;
string TR[4]={ "id","+","*","$"};
int getid(string a)
{
	for(int i=0;i<tn;i++)
	{
		if(TR[i].compare(a)==0)
		return i;
	}
}

string prece(string a,string b)
{
	return op[getid(a)][getid(b)];
}

void print(string ip[],int nip)
{
	cout<<endl;
	for(int i=0;i<=2*nip+2;i++)
	{
		cout<<ip[i];
	}
	cout<<endl;
}


void printprod(string a,int np)
{
	for(int i=0;i<np;i++)
	{
		int k=2;
		for(int j=2;array[i][j].compare("-1")!=0;j++)
		{
			if(array[i][j].compare(a)==0)
			{
				cout<<array[i][0]<<"->";
				for(int p=k;array[i][j].compare("-1")!=0;p++)
				cout<<array[i][j];
				
				cout<<endl;
				
				return;
			}
			else if(array[i][j].compare("/")==0)
			{
				k=j+1;
			}
		}
	}
}

int main()
{
	
	ifstream in;
	int np;
	cout<<"Enter No.of productions:";
	cin>>np;
	 in.open("prodop.txt",ios::in);

    for(int i=0,j=0;i<np;i++)
    {
       
        while(1)
        {
             in>>array[i][j];                                                                                                                                                                                                                                                                             
             if(array[i][j].compare("-1")==0)
             {
                 break;
             }
             j++;
        }
        j=0;
    }
    in.close();
	
    in.open("ptable.txt",ios::in);
	cout<<"Enter no.of terminals\n";
	cin>>tn;
    for(int i=0,j=0;i<tn;i++)
    {
       
        while(1)
        {
             in>>op[i][j];                                                                                                                                                                                                                                                                             
             if(op[i][j].compare("-1")==0)
             {
                 break;
             }
             j++;
        }
        j=0;
    }
    in.close();
    
    
	
	
	int nip;
	string ip[100];
	cout<<"Enter no.of terminals in i/p string:";
	cin>>nip;
	cout<<"Enter the i/p string:\n";
	ip[0]="$";
	for(int i=2;i<2*nip+2;i=i+2)
	{
		cin>>ip[i];
	}
	
	ip[2*nip+2]="$";
	
	for(int i=0;i<=2*nip;i=i+2)
	{
		ip[i+1]=prece(ip[i],ip[i+2]);
	}

	
	print(ip,nip);
	
	int flag=1;
	int lb=0,rb=0;
	for(int i=0;i<=2*nip+2;i++)
	{
		if(ip[i].compare("er")==0)
		flag=0;
		else if(ip[i].compare("<")==0)
		lb++;
		else if(ip[i].compare(">")==0)
		rb++;
		
	
	}
	
	cout<<endl;
	
	if(flag==1 && lb==rb)
	{
		for(int p=0;p<nip;p++)
		{
			for(int i=0;i<2*nip+2;i++)
			{
				if(ip[i].compare("@")==0)
				continue;
				else if(ip[i].compare(">")==0)
				{
					cout<<"handle :"<<ip[i-1]<<endl;
					//printprod(ip[i-1],np);
					int j=i;
					while(ip[j].compare("<")!=0)
					{
						ip[j--]="@";
					}
					int k=i+1;
					while(ip[k].compare("@")==0)k++;
					ip[j]=prece(ip[j-1],ip[k]);
					break;
				}
			}
			
			print(ip,nip);
		}
		cout<<"String accepted\n";
	}
	else
	{
		cout<<"Error parsing\n";
	}
	
	
	
	
}
