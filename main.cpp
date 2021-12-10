#include<iostream>
#include"test.h"
int main()
{
	int**k=new int*[6];
	int f;
	k[0]=&f;
	b_tree b1(3);
	int u;
	//std::cout<<"*****************************************************************************************\n";
	std::cout<<"new  program \n";
	/*
	b1.insert(b1.root,u=80);
	b1.insert(b1.root,u=90);
	b1.insert(b1.root,u=101);
	b1.insert(b1.root,u=1000);
	b1.insert(b1.root,u=900);
	b1.insert(b1.root,u=81);
	b1.insert(b1.root,u=85);
	*/
	b1.insert(b1.root,u=3);
	b1.insert(b1.root,u=10);
        b1.insert(b1.root,u=50);
        b1.insert(b1.root,u=20);
        b1.insert(b1.root,u=1);
        b1.insert(b1.root,u=5);
        b1.insert(b1.root,u=70);
        b1.insert(b1.root,u=80);
        b1.insert(b1.root,u=100);
        b1.insert(b1.root,u=101);
        b1.insert(b1.root,u=71);
        b1.insert(b1.root,u=75);
       // std::cout<<"*****************************************************************************************\n";
        b1.insert(b1.root,u=61);
        b1.insert(b1.root,u=51);
        b1.insert(b1.root,u=58);
	b1.insert(b1.root,u=12);
        b1.insert(b1.root,u=18); 
        b1.insert(b1.root,u=30);
        b1.insert(b1.root,u=79);
        b1.insert(b1.root,u=87);
	b1.insert(b1.root,u=1000);
        b1.insert(b1.root,u=900);
        b1.insert(b1.root,u=800);
        b1.insert(b1.root,u=600);
         b1.insert(b1.root,u=600);
        //std::cout<<"*****************************************************************************************\n";
        /*std::cout<<"*****************************************************************************************\n";
        std::cout<<u<<std::endl;*/
       /*
       qwe 
       */
       b1.del(b1.root,b1.root,u=900);
       //std::cout<<k[0]<<std::endl;
       //b1.reverse(b1.root);
       //b1.reverse(b1.root,u=0);
       
        b1.reverse(b1.root,u=0);
       b1.del(b1.root,b1.root,u=1000);
       b1.reverse(b1.root,u=0);
       std::cout<<"*****************************************************************************************\n";
       //b1.reverse(b1.root,u=0);
       //b1.del(b1.root,b1.root,u=79);
	//b1.del(b1.root,b1.root,u=80);
	//b1.del(b1.root,b1.root,u=79);
	//b1.del(b1.root,b1.root,u=61);
//b1.reverse(b1.root,u=0);	std::cout<<"*****************************************************************************************\n";
	//b1.reverse(b1.root,u=0);
	//b1.del(b1.root,b1.root,u=87);
	//b1.del(b1.root,b1.root,u=20);
	//b1.reverse(b1.root,u=0);
	//b1.del(b1.root,b1.root,u=30);
	//b1.del(b1.root,b1.root,u=18);
	//b1.del(b1.root,b1.root,u=1);
	//b1.del(b1.root,b1.root,u=80);
	//b1.del(b1.root,b1.root,u=71);
} 
