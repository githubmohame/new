#include<iostream>
using namespace std;
class node
{
	public:
	int arr[2]={0,0};
	node**no_num=new node*[3];
};
class b_tree
{
	int size;
	public:
	node*root;
	b_tree(int s1)
	{
		root=NULL;
		size=s1;
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
	void reverse(node*n1,int&counter,int num=0)
	{
		std::cout<<"the level ="<<num<<endl;
		cout<<n1<<endl;
		for(int i=0;i<size;i++)
		{
			//cout<<"the i ="<<i<<endl;
			if(n1->arr[i]!=0){
				std::cout<<n1->arr[i]<<"\t";
				counter+=1;
				}
		}
		std::cout<<"\n";
		for(int i=0;i<=size;i++)
		{
			if(n1->no_num[i]!=NULL)
				reverse(n1->no_num[i],counter,num+1);
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
			if(i!=size/2)
				new5->no_num[0]->arr[i]=arr[i];
			new5->no_num[0]->no_num[i]=n1->no_num[i];
		}
		int count=0;
		for(int i=size/2+1;i<=size+1;i++)
		{
			new5->no_num[1]->arr[count]=arr[i];
			new5->no_num[1]->no_num[count]=n1->no_num[i];
			count++;
		}
		//free(n1);
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
				if(k<n1->arr[i]||n1->arr[i]==0)
				{
					break;
				}
			}
			return i;
	}
	int found_postion_zero(node*n1)
	{
		int i;
		for(i=0;i<size;i++)
		{
			if(n1->arr[i]==0)
			{
				return i;
			}
		}
		return i;
	}
	node*insert(node*&n1,int&k)
	{
		if(k==5)
			cout<<"   qwertyuiop\n";
		if(root==NULL)
		{
			root=new node;
			root->arr[0]=k;
			return 0;
		}
		node*new2=NULL;
		int i=found_postion(n1,k),good_postion=i;//count the right postion of i;
		if(n1->no_num[i]!=NULL)
		{
			if(k==5)
				cout<<i<<"   qwertyuiop\n";
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
			if(k==5||k==3)
			{
				for(int i=0;i<=size;i++)
				{
					cout<<arr[i]<<"\t";
				}
				cout<<"\n";
			}
			node*new5=child(arr,n1);
			k=arr[size/2];
			if(i==size/2&&new2!=NULL)
			{
				int postion=found_postion_zero(new5->no_num[0]);
				int count=0;
				for(int m=postion;m<=size;m++)
				{
					if(i<size){
						new5->no_num[0]->arr[m]=new2->no_num[0]->arr[count];
						}
					new5->no_num[0]->no_num[m]=new2->no_num[0]->no_num[count];
					count++;
				}
				 postion=found_postion_zero(new5->no_num[1]);
				 count=size;
				 //error start from here
				 for(int m=postion-1;m>=0;)
				 {
				 	if(count<size)
				 	{	
				 		new5->no_num[1]->arr[count]=new5->no_num[1]->arr[m];
				 		m--;
				 	}
				 	new5->no_num[1]->no_num[count]=new5->no_num[1]->no_num[m];
				 	count--;
				 }
				 for(int m=0;m<=postion;m++)
				 {
				 	if(m<postion)
				 		{new5->no_num[1]->arr[m]=new2->no_num[1]->arr[m];
				 		}
				 	new5->no_num[1]->no_num[m]=new2->no_num[1]->no_num[m];
				 }
				 //end error here
			}
			else if(i<(size/2))
			{
				int f=i;
				f=abs(f);
				if(new2!=NULL)
				{new5->no_num[0]->no_num[f]=new2->no_num[0];
				new5->no_num[0]->no_num[f+1]=new2->no_num[1];}
			}
			else if(i>(size/2))
			{
				int f=size-i;
				f=abs(f);
				if(new2!=NULL)
				{new5->no_num[1]->no_num[f]=new2->no_num[0];
				new5->no_num[1]->no_num[f+1]=new2->no_num[1];}
			}
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
			return new5;
		}
		if(!full(n1->arr,size))
		{
		// put element at postion array of node n1 is not full
			int u2=found_postion_zero(n1);
			for(u2;u2>=i;u2--)
			{
					if(u2<found_postion_zero(n1))
					{n1->arr[u2+1]=n1->arr[u2];}
					if(new2!=NULL){
						n1->no_num[u2+1]=n1->no_num[u2];
						cout<<"the u2= "<<u2<<endl;;
						}	
			}
			n1->arr[i]=k;
			if(new2!=NULL){
			n1->no_num[i]=new2->no_num[0];
			n1->no_num[i+1]=new2->no_num[1];}
			k=0;
			return NULL;
		}
	}
};

/*

void b_tree::del(node*&n1,node*&n2,int&k)
	{
		if(root==NULL)
		{
			std::cout<<"the tree is null";
		}
		int i;
		for(i=0;i<=size;i++)
		{
			if(i!=size&&n1->arr[i]>k)
			{
				if(n1->no_num!=NULL)
					del(n1->no_num[i],n1,k);
					k=0;
				break;
			}
			else if(i==size&&n1->arr[i]<k)
			{
				if(n1->no_num!=NULL)
					del(n1->no_num[size],n1,k);
				else
					k=0;
				break;
			}
			else if(n1->arr[i]==k)
			{
				break;
			}
		}
		//std::cout<<n1->no_num[i]<<"                yyyyyyyyyyyyyyyyyyyyyyyyyyy"<<" ggttyhuii \n";
		if(n1->no_num[i]==NULL&&k!=0)
		{
			int pos1;
			int end1=found_size(n1,pos1);
			int i2=0;
			for(i2=0;i2<=size;i2++)
			{
				if(k==79)
				{
					std::cout<<i2<<"  kiihhuii\t"<<std::endl;
				}
				if(i2!=size&&n2->arr[i2]>k)
				{
					break;
				}
				else if(i2==size)
				{
					break;
				}
			}
			std::cout<<-1*pos1+end1-1<<i2<<" jjjj\n";
			if(-1*pos1+end1-1 >size/2)
			{
				n1->arr[i]=0;
				int i3;
				//std::cout<<i<<"\t"<<end1<<"\n";
				for(i3=i;i3<end1;i3++)
				{
					n1->arr[i3]=n1->arr[i3+1];
					if(n1->arr[i3+1]==0)
					{
						break;
					}		
				}
				n1->arr[i3]=0;
			}
			else if((-1*pos1+end1-1<=size/2)&&i2==size)
			{
				int pos2;
				int end2=found_size(n2->no_num[i2-1],pos2);
				if(-1*pos2+end2 >size/2)
				{
					n1->arr[i]=0;
					for(int i3=i;i3<end1;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								n1->arr[i3]=0;
								break;
							}			
						}
					pos1;
					end1=found_size(n1,pos1);
					if(pos1>0)
						n1->arr[pos1-1]=n2->arr[size-1];
					else
					{
						for(int i3=end1-1;i3>=0;i3--)
						{
							n1->arr[i3+1]=n1->arr[i3];
						}
						n1->arr[pos1]=n2->arr[size-1];
					}
					n2->arr[size-1]=n2->no_num[i2-1]->arr[end2-1];
					n2->no_num[i2-1]->arr[end2-1]=0;
				}
				else
				{
					int num1=n1->arr[i];
					//std::cout<<k<<"\t"<<n1->arr[i]<<" jjjj\n";
					int right_pos;
					//std::cout<<"\tkkklllkkkk"<<"\n";
					merge(n2,n2->no_num[size-1],n1,i2,0);
					for(int i3=0;i3<size;i3++)
					{
						std::cout<<n2->no_num[i2-1]<<"  yuytwewq123\n";
						if(num1==n2->no_num[i2-1]->arr[i3])
						{
							n2->no_num[i2-1]->arr[i3]=0;
							right_pos=i3;
							break;
						}
					}
					std::cout<<"jjjjkkkkkkklllllllllllllllllllll\n";
					for(int i3=right_pos;i3<end1;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								n1->arr[i3]=0;
								break;
							}		
						}
				}
			}
			else if((-1*pos1+end1-1<size/2)&&i2==0)
			{
				int pos2;
				int end2=found_size(n2->no_num[i2+1],pos2);
				if(-1*pos2+end2 >=size/2)
				{
					n1->arr[i]=0;
					for(int i3=i;i3<end1;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								n1->arr[i3]=0;
								break;
							}		
						}
						n1->arr[end1]=n2->arr[i2];
						n2->arr[i2]=n2->no_num[i2+1]->arr[pos2];
						n2->no_num[i2+1]->arr[pos2]=0;	
				}
				else if(n2->no_num[1]!=NULL)
				{
					int num1=n1->arr[i];
					int right_pos;
					merge(n2,n1,n2->no_num[1],i2,1);
					for(int i2=0;i2<size;i2++)
					{
						if(num1==n2->arr[i2])
						{
							n2->arr[i2]=0;
							right_pos=i2;
							break;
						}
					}
					for(int i3=right_pos;i3<end1;i3++)
					{
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								n1->arr[i3]=0;
								break;
							}		
					}
				}
				else 
				{
					n1->arr[i]=0;
						int i3;
						//std::cout<<i<<"\t"<<end1<<"\n";
						for(i3=i;i3<end1;i3++)
						{
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								break;
							}		
						}
						n1->arr[i3]=0;	
						if(i3==1)
						{
							free(n2->no_num[i2]);
							n2->no_num[i2]=NULL;
						}
				}
			}
			else
			{
					bool flage2=0;
					std::cout<<" ggttyhuii \n";
					//error logic 
					if(k==79)
						std::cout<<i2-1<<"        ggjjjjjjjjjjjjj\t "<< "\n";
					if(n2->no_num[i2-1]!=NULL&&!flage2)
					{
						int pos2;
						int end2=found_size(n2->no_num[i2-1],pos2);
						if((-1*pos2+end2-1>=size/2))
						{
							n1->arr[i]=0;
							for(int i3=i;i3<end1;i3++){
									n1->arr[i3]=n1->arr[i3+1];
									if(n1->arr[i3+1]==0)
									{
										n1->arr[i3]=0;
										break;
									}		
								}
							end1--;
							if(pos1>0)
								n1->arr[pos1-1]=n2->arr[i2-1];
							else{
								for(int i3=end1-1;i3>=0;i3--){
									n1->arr[i3+1]=n1->arr[i3];
								}
								//std::cout<<n1->arr[pos1]<<" ggttyhuii \n";
								n1->arr[pos1]=n2->arr[i2-1];
								//std::cout<<n2->arr[i2-1]<<" ggttyhuii \n";
							}
							n2->arr[i2-1]=n2->no_num[i2-1]->arr[end2-1];
							n2->no_num[i2-1]->arr[end2-1]=0;
							flage2=1;
						}
					}
					if(n2->no_num[i2+1]!=NULL&&!flage2)
					{
						int pos2;
						int end2=found_size(n2->no_num[i2+1],pos2);
						if(-1*pos2+end2-1>=size/2)
						{
							n1->arr[i]=0;
							for(int i3=i;i3<end1;i3++)
							{
								n1->arr[i3]=n1->arr[i3+1];
								if(n1->arr[i3+1]==0)
								{
									n1->arr[i3]=0;
									break;
								}		
							}
							n1->arr[end1]=n2->arr[i2-1];
							n2->arr[i2]=n2->no_num[i2+1]->arr[pos2];
							n2->no_num[i2+1]->arr[pos2]=0;
							flage2=1;
						}
					}
					if(n2->no_num[i2-1]!=NULL&&!flage2)
					{
						int num1=n1->arr[i];
						int right_pos;
						merge(n2,n2->no_num[i2-1],n1,i2,0);
						for(int i3=0;i3<size;i3++)
						{
							if(num1=n2->no_num[i2-1]->arr[i3])
							{
								n2->no_num[i2-1]->arr[i3]=0;
								right_pos=i3;
								break;
							}
							
						}
						for(int i3=right_pos;i3<end1;i3++)
						{
								n2->no_num[i2-1]->arr[i3]=n2->no_num[i2-1]->arr[i3+1];
								if(n2->no_num[i2-1]->arr[i3+1]==0)
								{
									n2->no_num[i2-1]->arr[i3]=0;
									break;
								}		
							}
						flage2=1;
					}
					if(n2->no_num[i2+1]!=NULL&&!flage2)
					{
						int num1=n1->arr[i];
						//std::cout<<num1<<"  ghhjkkhy "<<std::endl;
						int right_pos;
						merge(n2,n1,n2->no_num[i2+1],i2,1);
						for(int i2=0;i2<size;i2++)
						{
							if(num1==n2->arr[i2])
							{
								n2->arr[i2]=0;
								right_pos=i2;
								break;
							}
						}
						for(int i3=right_pos;i3<end1;i3++)
						{
								n1->arr[i3]=n1->arr[i3+1];
								if(n1->arr[i3+1]==0)
								{
									n1->arr[i3]=0;
									break;
								}		
						}
						flage2=1;
					}
					if(!flage2)
					{
						n1->arr[i]=0;
						int i3;
						//std::cout<<i<<"\t"<<end1<<"\n";
						for(i3=i;i3<end1;i3++)
						{
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								break;
							}		
						}
						n1->arr[i3]=0;	
						if(i3==1)
						{
							free(n2->no_num[i2]);
							n2->no_num[i2]=NULL;
						}
	
					}
				}
			}
			else if(n1->no_num[i]!=NULL&&k!=0)
			{
				node *nt1=n1->no_num[i+1];
				node *nt2=n1->no_num[i+1];
				int num;
				returnTheEnd(nt1,nt2,num);
				int num2=nt1->arr[num];
				b_tree::del(root,root,nt1->arr[num]);
				n1->arr[i]=num2;
			}
		}
		
		
		int returnTheEnd(node*nt1,int num)
	{
		int pos;
		found_size(nt1,pos);
		if(nt1->no_num[pos]!=NULL)
		{
			return returnTheEnd(nt1,num);
		}
		else
			return nt1->arr[pos];
	}
	*/
