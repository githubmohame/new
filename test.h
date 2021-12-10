#include<iostream>
class node
{
	public:
	int arr[3]={0,0,0};
	node**no_num=new node*[4];
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
	int returnTheEnd(node*nt1)
	{
		int pos;
		found_size(nt1,pos);
		//std::cout<<"qwasderfgtyhy\t"<<nt1<<"\n";
		if(nt1->no_num[pos]!=NULL)
		{
			return returnTheEnd(nt1->no_num[pos]);
		}
		else
			return nt1->arr[pos];
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
			if(n1->arr[i2]==0)
			{
				break;
			}
		}
		return i2;
	}
	
	void merge(node*&n1,node*&left,node*&right,int pos,bool flage)
	{
		int pos1=0;
		int end1=found_size(right,pos1);
		int pos2=0;
		int end2=found_size(left,pos2);
		int last1=size;
		if(flage)
		{	
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
				//std::cout<<left->arr[i]<<"  gghhjj  \n";
				if(left->arr[i]==0)
				{
					break;
				}
				left->no_num[start]=left->no_num[i];
				start++;
			}
			left->arr[start]=n1->arr[pos-1];
			n1->arr[pos-1]=0;
			start++;
			for(int i=pos1;i<=end1-1;i++)
			{
				left->arr[start]=right->arr[i];
				left->no_num[start]=right->no_num[i];
				start++;
			}
			left->no_num[start]=right->no_num[end1+1];
			free(right);
			n1->no_num[pos]=NULL;
		}
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
	void reverse(node*n1,int num=0)
	{
		std::cout<<"the level ="<<num<<std::endl;
		for(int i=0;i<=size;i++)
		{
			if(i<size)
				std::cout<<"\t"<<n1->no_num[i]<<"\t"<<n1->arr[i] <<"\t";
			else
				std::cout<<n1->no_num[i]<<"\t";
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
			if(i!=size/2)
				new5->no_num[0]->arr[i]=arr[i];
			new5->no_num[0]->no_num[i]=n1->no_num[i];
		}
		int count=0;
		for(int i=size/2+1;i<=size;i++)
		{
			if(count<size){
				new5->no_num[1]->arr[count]=arr[i];
			}
			new5->no_num[1]->no_num[count]=n1->no_num[i];
			count++;
		}
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
	node*insert(node*&n1,int&k)
	{
		if(root==NULL)
		{
			root=new node;
			root->arr[0]=k;
			return 0;
		}
		node*new2=NULL;
		int i=found_postion(n1,k);//count the right postion of i;
		if(k==70)
			{
				//std::cout<<i<<"   qwsdfrtghy\n";
				//std::cout<<full(n1->arr,size)<<"   123refs\n";
			}
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
			/*for(int i=0;i<size+1;i++)
			{std::cout<<arr[i]<<"\t";}
			std::cout<<"\n";*/
			node*new5=child(arr,n1);
			k=arr[size/2];
			if(k==50)
			{
				//std::cout<<"qwedf 123\n";
			}
			count=0;
			for(int m=0;m<size+1;m++)
			{
				if(m==size/2)
					continue;
				n1->arr[count]=arr[m];
				count++;
			}
			if(i==size/2&&new2!=NULL)
			{
				if(k==71)
				{
					//std::cout<<"the k is="<<k<<"\n";
				}
				int postion=found_postion_zero(new5->no_num[0]);
				int count=0;
				for(int m=postion;m<=size;m++)
				{
					if(m<size){
						new5->no_num[0]->arr[m]=new2->no_num[0]->arr[count];
						}
					new5->no_num[0]->no_num[m]=new2->no_num[0]->no_num[count];
					if(count==size+1)
					{break;}
					count++;
				}
				 //std::cout<<"the position = "<<postion<<"\n";
				 postion=found_postion_zero(new5->no_num[1]);
				 count=size;
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
				 		new5->no_num[1]->arr[m]=new2->no_num[1]->arr[m];
				 	new5->no_num[1]->no_num[m]=new2->no_num[1]->no_num[m];
				 }
				 //std::cout<<size<<"\n";
			}
			if(i-size/2<0)
			{
				int f=i;
				if(new2!=NULL)
				{
					int pos=found_postion_zero(new5->no_num[0]);
					new5->no_num[0]->no_num[f]=new2->no_num[0];
					if(new5->no_num[0]->no_num[f+1]==NULL)
						new5->no_num[0]->no_num[f+1]=new2->no_num[1];
					else
					{
						for(int m=size;m>=pos;m--)
						{
							new5->no_num[0]->no_num[m]=new5->no_num[0]->no_num[m-1];
						}
						new5->no_num[0]->no_num[pos]=new2->no_num[1];
					}
					free(n1);
				        n1=NULL;
				}
			}
			else if(i-size/2>0)
			{
				int pos=found_postion_zero(new5->no_num[1]);
				int f=abs(i-(size/2)-1);
				if(new2!=NULL)
				{
					new5->no_num[1]->no_num[f]=new2->no_num[0];
					if(new5->no_num[0]->no_num[f+1]==NULL)
						new5->no_num[1]->no_num[f+1]=new2->no_num[1];
					else
					{
						for(int m=size;m>=pos;m--)
						{
							new5->no_num[1]->no_num[m]=new5->no_num[1]->no_num[m-1];
						}
						new5->no_num[1]->no_num[pos]=new2->no_num[1];
					}
					free(n1);
					n1=NULL;
				}
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
			k=0;
			return NULL;
		}
	return NULL;}	
	void del(node*&,node*&,int&);
};
void b_tree::del(node*&n1,node*&n2,int&k)
	{
		if(root==NULL)
		{
			std::cout<<"the tree is null";
		}
		int i;
		int pos200;
		found_size(n1,pos200);
		for(i=pos200;i<=size;i++)
		{
			if(i!=size&&n1->arr[i]>k||n1->arr[i]==0)
			{
				if(n1->no_num[i]!=NULL)
					del(n1->no_num[i],n1,k);
				k=0;
				break;
			}
			else if(i==size&&n1->arr[i]<k)
			{
				if(n1->no_num[size]!=NULL)
					del(n1->no_num[size],n1,k);
				k=0;
				break;
			}
			else if(n1->arr[i]==k)
			{
				if(k==100)
				{
					//std::cout<<"            the number is 100"<<std::endl;
				}
				break;
			}
		}
		if(n1->no_num[i]==NULL&&k!=0)
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
				else if(i2==size)
				{
					break;
				}
			}
			if(-1*pos1+end1-1 >=size/2)
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
			else if((-1*pos1+end1-1<size/2)&&i2==size)
			{
				int pos2;
				int end2=found_size(n2->no_num[i2-1],pos2);
				if(k==1000)
				std::cout<<i2<<"                yyyyyyyyyyyyyyyyyyyyyyyyyyy"<<" ggttyhuii \n";
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
						//std::cout<<n2->no_num[i2-1]<<"  yuytwewq123\n";
						if(num1==n2->no_num[i2-1]->arr[i3])
						{
							n2->no_num[i2-1]->arr[i3]=0;
							right_pos=i3;
							break;
						}
					}
					//std::cout<<"jjjjkkkkkkklllllllllllllllllllll\n";
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
				if(-1*pos2+end2 >size/2)
				{
					n1->arr[i]=0;
					int i3;
					for(i3=i;i3<end1;i3++){
							n1->arr[i3]=n1->arr[i3+1];
							if(n1->arr[i3+1]==0)
							{
								n1->arr[i3]=0;
								break;
							}		
						}
						n1->arr[i3]=n2->arr[i2];
						n2->arr[i2]=n2->no_num[i2+1]->arr[pos2];
						n2->no_num[i2+1]->arr[pos2]=0;	
				}
				else
				{
					if(k==1)
					{
						//std::cout<<-1*pos1+end1-1<<"\t\f"<<-1*pos2+end2;
					}
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
				
			}
			else
			{
					bool flage2=0;
					//error logic 
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
						//std::cout<<n1<< "\n";
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
				}
				k=0;
			}
			else if(n1->no_num[i]!=NULL&&k!=0)
			{
				int u;
				node *nt1=n1->no_num[i+1];
				int num;
				int f;
				num=returnTheEnd(n1->no_num[i+1]);
				del(this->root,this->root,f=num);
				int num2=num;
				n1->arr[i]=num2;
				//reverse(root,u=0);
				//std::cout<<num<<"     hhhhhhhhhhhhhhhhhhhh\n";
				k=0;
				return;
			}
		}
		
		
