#include<iostream>
#include<cmath>
using namespace std;
class node
{
	public:
	int arr[3]={0,0};
	node**no_num=new node*[3];
};
class b_tree
{
	long long  int size=0;
	public:
	node*root=NULL;
	b_tree(int s1)
	{
		root=NULL;
		size=s1;
	}
	static int size1(int arr[])
	{
		for(int i=0;i<size;i++)
		{
			if(arr[i]==0)
			{
				return i-1;
			}
		}
		return size;
	}
	int find(int arr[],int k)
	{
		for(int i=0;i<size;i++)
		{
			if(arr[i]>=k)
			{
				return i;
			}
			else if(arr[i]==0)
			{
				return i-1;
			}
		}
		return i;
	}
	bool full(int arr[],int size)
	{
		for(int i=0;i<size;i++)
		{
			if(arr[i]==0)
			{
				return 0;
			}
		}
		return 1;
	}
	int found_size(node*n1,int&pos)
	{
		int i;
		for(i=0;i<size;i++)
		{
			if(n1->arr[i]!=0)
			{
				break;
			}
		}
		int i2;
		pos=i;
		for(i2=i;i2<size;i2++)
		{
			if(n1->arr[i]==0)
			{
				break;
			}
		}
		return i2;
	}
	void reverse(node*n1,int num=0)
	{
		std::cout<<"the level ="<<num<<endl;
		for(int i=0;i<size;i++)
		{
			if(n1->arr[i]!=0)
				std::cout<<n1->arr[i]<<"\t";
		}
		std::cout<<"\n";
		for(int i=0;i<=size;i++)
		{
			if(n1->no_num[i]!=NULL)
				reverse(n1->no_num[i],num+1);
		}
	}
	// make child for the node for more info go to line 1;
	node* child(int arr[],node*&n1)
	{
		node*new5=new node;
		new5->arr[0]=arr[size/2];
		new5->no_num[0]=new node;
		new5->no_num[1]=new node;
		for(int i=0;i<=size/2;i++)
		{
			if(i<size/2)
				new5->no_num[0]->arr[i]=arr[i];
			new5->no_num[0]->no_num[i]=n1->no_num[i];
		}
		int count=0;
		for(int i=size/2+1;i<=size;i++)
		{
			new5->no_num[1]->arr[count]=arr[i];
			new5->no_num[1]->no_num[count]=n1->no_num[i];
			count++;
		}
		free(n1);
		return new5;
	}
	int found_postion(node*n1,int k)
	{
			int i;
			for(i=0;i<=size;i++)
			{
				if(i==size)
				{
					break;
				}
				if(k<=n1->arr[i]||n1->arr[i]==0)
				{
					break;
				}
			}
			return i;
	}
	void merge(node*n1,node*left,node*right,int pos,bool flage)
	{
		if(flage)
		{
			int pos1=0;
			int end1=found_size(right,pos1);
			int pos2=0;
			int end2=found_size(left,pos2);
			int last1=size;
			for(int i=end1;i>=pos1;i--)
			{
				if(i<size){
					right->arr[last1]=right->arr[i];
					last1--;
					}
				right->no_num[last1]=right->no_num[i];
			}
			right->arr[last1]=n1->arr[pos];
			n1->arr[pos]=0;
			last1--;
			for(int i=end2;i>=pos2;i--)
			{
				if(i!=end2){
					right->arr[last1]=left->arr[i];
					last1--;
					}
				right->no_num[last1]=left->no_num[i];
			}
			free(left);
			n1->no_num[pos]=NULL;
		}
		else
		{
			int start=0;
			for(int i=pos2;i<=end2;i++)
			{
				
				left->arr[start]=left->arr[i];
				left->no_num[start]=left->no_num[i];
				start++;
			}
			left->arr[start]=n1->arr[pos+1];
			n1->arr[pos+1]=0;
			start++;
			for(int i=pos1;i<=end1;i++)
			{
				left->arr[start]=right->arr[i];
				left->no_num[start]=right->no_num[i];
				start++;
			}
			left->no_num[start]=right->no_num[end1+1];
			free(right);
			n1->no_num[pos+1]=NULL;
		}
	}
	node*insert(node*&n1,int&k)
	{
		node*new2=NULL;
		if(root==NULL)
		{
			root=new node;
			root->arr[0]=k;
			return 0;
		}
		int i=found_postion(n1,k);//count the right postion of i;
		if(n1->no_num[i]!=NULL)
		{
			new2=insert(n1->no_num[i],k);
		}
		if(k==0)
		{
			return 0;
		}
		if(full(n1->arr,size))
		{
			int count=0;
			int*arr=new int[size+1];
			for(int m=0;m<size+1;m++)
			{
				if(i==m)
				{
					arr[m]=k;
					continue;
				}
				arr[m]=n1->arr[count];
				count++;
			}
			node*new5=child(arr,n1);
			if(i==size/2&&new2!=NULL)
			{
				
				int postion=found_postion_zero(new5->no_num[0]);
				int count=0;
				for(int m=postion-1;m<=size;m++)
				{
					if(i<size){
						new5->no_num[0]->arr[m]=new2->no_num[0]->arr[count];
						}
					new5->no_num[0]->no_num[m]=new2->no_num[0]->no_num[count];
					count++;
				}
				 postion=found_postion_zero(new5->no_num[1]);
				 count=size;
				 for(int m=postion-1;m>=0;m--)
				 {
				 	if(count<size)
				 	{
				 		new5->no_num[1]->arr[count]=new5->no_num[1]->arr[m];
				 	}
				 	new5->no_num[1]->no_num[count]=new5->no_num[1]->no_num[m];
				 	count--;
				 }
				 for(int m=0;m<=postion-1;m++)
				 {
				 	if(i<postion)
				 		new5->no_num[1]->arr[m]=new2->no_num[1]->arr[m];
				 	new5->no_num[1]->no_num[m]=new2->no_num[1]->no_num[m];
				 }
			}
			else if(i-size<0)
			{
				int f=size-i;
				f=abs(f);
				if(new2!=NULL)
				{new5->no_num[0]->no_num[f]=new2->no_num[0];
				new5->no_num[0]->no_num[f+1]=new2->no_num[1];}
			}
			else if(i-size >=0)
			{
				int f=size-i;
				f=abs(f);
				if(new2!=NULL)
				{new5->no_num[1]->no_num[f]=new2->no_num[0];
				new5->no_num[1]->no_num[f+1]=new2->no_num[1];}
			}
			/*for(int m=0;m<size+1;m++)
			{cout<<arr[m]<<"\t";}
			cout<<"\n";
			*/
			k=arr[size/2];
			count=0;
			for(int m=0;m<size+1;m++)
			{
				if(m==size/2)
					continue;
				n1->arr[count]=arr[m];
				count++;
			}
			if(n1==root)
			{
				root=new5;
			}
			//std::cout<<k<<endl;
			return new5;
		}
		else if(!full(n1->arr,size))
		{
		// put element at postion array of node n1 is not full
			for(int u2=size-1;u2>=i;u2--)
			{
					if(u2<size-1)
					{n1->arr[u2+1]=n1->arr[u2];}
					if(new2!=NULL){
						n1->no_num[u2+1]=n1->no_num[u2];
						}	
			}
			n1->arr[i]=k;
			if(new2!=NULL){
			n1->no_num[i]=new2->no_num[0];
			n1->no_num[i+1]=new2->no_num[1];}
			
			/*if(k==50)
			{
				std::cout<<new2<<"\n";
				for(int i=0;i<size;i++)
				{std::cout<<n1->arr[i]<<"\t";}
				std::cout<<"\n";
			}
			*/
			k=0;
			return NULL;
		}
	}
	void del(node*&n1,node*&n2,int&k)
	{
		if(root==NULL)
		{
			cout<<"the tree is null";
		}
		int i;
		for(i=0;i<=size;i++)
		{
			if(i!=size&&n1->arr[i]>k)
			{
				if(node*&n1->no_num!=NULL)
					del(node*&n1->no_num[size],n1,k);
				break;
			}
			else if(i==size&&n1->arr[i]<k)
			{
				if(node*&n1->no_num!=NULL)
					del(node*&n1->no_num[size],n1,k);
				else
					k=0;
				break;
			}
			else if(n1->arr[i]==k)
			{
				break;
			}
		}
		if(n1->no_num[i]==NULL)
		{
			int pos1;
			int end1=found_size(n1,pos1);
			int i2=0;
			for(i2=0;i2<=size;i2++)
			{
				if(i2!=size&&n2->arr[i2]>k)
				{
					break;
				}
				else if(i2==size&&n1->arr[i]<k)
				{
					break;
				}
			}
			if(-1*pos1+end1 >=size/2)
			{
				n1->arr[i]=0;
			}
			else if((-1*pos1+end1<size/2)&&i2==size)
			{
				int pos2;
				int end2=found_size(n2->no_num[i2-1]->arr,pos2);
				if(-1*pos2+end2 >=size/2)
				{
					n1->arr[i]=0;
					for(int i3=i;i3<endl;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								(n1->arr[i3]=0;
								break;
							}		
						}
					if(pos1>0)
						n1->arr[pos1-1]=n2->arr[size-1];
					else{
						for(int i3=end1-1;i3<=0;i3--){
							n1->arr[i3+1]=n1->arr[i3];	
						}
						n1->arr[pos1]=n2->arr[size-1];
					}
					n2->arr[size-1]=n2->no_num[i2]->arr[pos2];
					n2->no_num[i2]->arr[pos2]=0;
				}
				else
				{
					int num1=n1->arr[i];
					int right_pos;
					merge(n2,n1,n2->no_num[size],i2,0);
					for(int i2=0;i2<size;i2++)
					{
						if(num1==n2>arr[i2])
						{
							n2>arr[i2]=NULL;
							right_pos=i2;
							break;
						}
					}
					for(int i3=right_pos;i3<endl;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								(n1->arr[i3]=0;
								break;
							}		
						}
				}
			}
			else if((-1*pos1+end1<size/2)&&i2==0)
			{
				int pos2;
				int end2=found_size(n2->no_num[i2+1]->arr,pos2);
				if(-1*pos2+end2 >=size/2)
				{
					n1->arr[i]=0;
					for(int i3=i;i3<endl;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								(n1->arr[i3]=0;
								break;
							}		
						}
						n1->[end1]=n2->arr[i2];
						n2->arr[i2]=n2->no_num[i2+1]->arr[pos2];
						n2->no_num[i2+1]->arr[pos2]=0;	
				}
				else
				{
					int num1=n1->arr[i];
					int right_pos;
					merge(n2,n1,n2->no_num[1],i2,1);
					for(int i2=0;i2<size;i2++)
					{
						if(num1==n2>arr[i2])
						{
							n2>arr[i2]=NULL;
							right_pos=i2;
							break;
						}
					}
					for(int i3=right_pos;i3<endl;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								(n1->arr[i3]=0;
								break;
							}		
						}
				}
				
			}
			else
			{
					if(n2->no_num[i2-1]!=NULL){
						int pos2;
						int end2=found_size(n2->no_num[i2-1]->arr,pos2);
						if((-1*pos2+end2>=size/2)
						{
							n1->arr[i]=0;
							for(int i3=i;i3<endl;i3++){
									n1->arr[i3]=n1->arr[i3+1];
									if(n1->arr[i3+1]==0)
									{
										n1->arr[i3]=0;
										break;
									}		
								}
							if(pos1>0)
								n1->arr[pos1-1]=n2->arr[i2-1];
							else{
								for(int i3=end1-1;i3<=0;i3--){
									n1->arr[i3+1]=n1->arr[i3];	
								}
								n1->arr[pos1]=n2->arr[i2-1];
							}
							n2->arr[i2-1]=n2->no_num[i2]->arr[pos2];
							n2->no_num[i2]->arr[pos2]=0;
						}
					}
					else if(n2->no_num[i2+1]!=NULL)
					{
						int pos2;
						int end2=found_size(n2->no_num[i2+1]->arr,pos2);
						if(-1*pos2+end2>=size/2)
						{
							n1->arr[i]=0;
							for(int i3=i;i3<endl;i3++){
								n1->arr[i3]=n1->arr[i3+1];
								if(n1->arr[i3+1]==0)
								{
									n1->arr[i3]=0;
									break;
								}		
							}
							n1->[end1]=n2->arr[i2-1];
							n2->arr[i2]=n2->no_num[i2+1]->arr[pos2];
							n2->no_num[i2+1]->arr[pos2]=0;
						}
					}
					else if(n2->no_num[i2-1]!=NULL)
					{
						int num1=n1->arr[i];
						int right_pos;
						merge(n2,n1,n2->no_num[i2],i2,0);
						for(int i2=0;i2<size;i2++)
						{
							if(num1==n2>arr[i2])
							{
								n2>arr[i2]=NULL;
								right_pos=i2;
								break;
							}
						}
						for(int i3=right_pos;i3<endl;i3++){
								n1->arr[i3]=n1->arr[i3+1];
								if(n1->arr[i3+1]==0)
								{
									(n1->arr[i3]=0;
									break;
								}		
							}
					}
					else if(n2->no_num[i2-1]!=NULL)
					{
						int num1=n1->arr[i];
						int right_pos;
						merge(n2,n1,n2->no_num[1],i2,1);
						for(int i2=0;i2<size;i2++)
						{
							if(num1==n2>arr[i2])
							{
								n2>arr[i2]=NULL;
								right_pos=i2;
								break;
							}
						}
						for(int i3=right_pos;i3<endl;i3++)
						{
								n1->arr[i3]=n1->arr[i3+1];
								if(n1->arr[i3+1]==0)
								{
									(n1->arr[i3]=0;
									break;
								}		
						}
					}
				}
			}
		}
	}
};
