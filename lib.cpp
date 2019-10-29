#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;

/////////////////////////////// classes ////////////////////////////////////////////////

class RESV;


class HOTEL {
	public:
	
		int id;
		char name[256];
		int stars_hotel;
		int rooms;
		RESV *R;
		int NK;
		
	HOTEL();
	void set(int idv,const char nv[256],int st,int r,RESV *K,int nk );
	
	void print();
	void read();
};



class RESV{
	public:
		char name[50];
		char hm_afixis[80];
		int Diarkeia;

	RESV ();
	void set(const char nv[50],const char hm_af[80],int dr);
		void print();
		void read();
};


class Node
{
	public:
       int key;
       char color;
       Node *parent;
       Node *left, *right;
       
       Node();
};


class AVLtree
{
      Node *root;
   
   public :
   
      AVLtree()
      {
         root=NULL;
      }
	  
      void insert(int x);
      void insertfix(Node *);
      void leftrotate(Node *);
      void rightrotate(Node *);
      Node* successor(Node *);
      int search(int x);
};


	HOTEL::HOTEL()
	{
		id=0; strcpy(name,""); 
		stars_hotel=0; rooms=0; 
		NK=0; 
	}
	
	
	void HOTEL::set(int idv,const char nv[256],int st,int r,RESV *K,int nk )
	{
		id=idv; strcpy(name,nv);
		stars_hotel=st; rooms=r; 
	    R=K; NK=nk;
	}


	void HOTEL::print()
	{
		cout<<"id:"<<id<<" name:"<<name<<" stars_hotel:"<<stars_hotel<<" number of rooms:"<<rooms<<endl;
		for (int j=0;j<NK;j++)
			R[j].print();
		cout<<endl<<endl;	
			
				
	}
	
	void HOTEL::read()
	{
		cout<<"id:"; 	cin>>id;
		cout<<"name:"; 	cin>>name;
		cout<<"stars_hotel:"; 	cin>>stars_hotel;
		cout<<"number of rooms:"; 	cin>>rooms;
		cout<<"number of RESVs:"; cin>>NK;
		
		R= (RESV * ) malloc(NK*sizeof(RESV));
		for (int j=0;j<NK;j++)
		{
			cout<<"\n\nKratisi "<<j; 
			R[j].read();
		}
		
				
	}





	RESV::RESV ()
	{ 
		strcpy(name,""); strcpy(hm_afixis,""); Diarkeia=0;
	}
	
	void RESV::set(const char nv[50],const char hm_af[80],int dr)
	{
		strcpy(name,nv); strcpy(hm_afixis,hm_af); Diarkeia=dr;
	}
	
	void RESV::print()
	{
		cout<<"name:"<<name<<" Mera_kratisis:"<<hm_afixis<<" Diarkeia:"<<Diarkeia<<endl;
	}
	
	
	void RESV::read()
	{
		cout<<"name:"; cin>>name;
		cout<<"hm_afixis:"; cin>>hm_afixis;
		cout<<"Diarkeia:"; cin>>Diarkeia;
	}




HOTEL *TableData;



 Node::Node()
	   {
		   key=-1;
		   parent=NULL;
		   color='r';
		   left=NULL;
		   right=NULL; 
	   }
	   

void AVLtree::insert(int x)
{
     int i=0;

     Node *p,*q;
     Node *t=new Node;
     t->key=x;
     t->left=NULL;
     t->right=NULL;
     t->color='r';
     p=root;
     q=NULL;
     if(root==NULL)
     {
           root=t;
           t->parent=NULL;
     }
     else
     {
         while(p!=NULL)
         {
              q=p;
              if(p->key<t->key)
                  p=p->right;
              else
                  p=p->left;
         }
         t->parent=q;
         if(q->key<t->key)
              q->right=t;
         else
              q->left=t;
     }
     insertfix(t);
};
void AVLtree::insertfix(Node *t)
{
     Node *u;
     if(root==t)
     {
         t->color='b';
         return;
     }
     while(t->parent!=NULL&&t->parent->color=='r')
     {
           Node *g=t->parent->parent;
           if(g->left==t->parent)
           {
                        if(g->right!=NULL)
                        {
                              u=g->right;
                              if(u->color=='r')
                              {
                                   t->parent->color='b';
                                   u->color='b';
                                   g->color='r';
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->parent->right==t)
                            {
                                 t=t->parent;
                                 leftrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            rightrotate(g);
                        }
           }
           else
           {
                        if(g->left!=NULL)
                        {
                             u=g->left;
                             if(u->color=='r')
                             {
                                  t->parent->color='b';
                                  u->color='b';
                                  g->color='r';
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->parent->left==t)
                            {
                                   t=t->parent;
                                   rightrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            leftrotate(g);
                        }
           }
           root->color='b';
     }
};

void AVLtree::leftrotate(Node *p)
{
     if(p->right==NULL)
           return ;
     else
     {
           Node *y=p->right;
           if(y->left!=NULL)
           {
                  p->right=y->left;
                  y->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root=y;
           else
           {
               if(p==p->parent->left)
                       p->parent->left=y;
               else
                       p->parent->right=y;
           }
           y->left=p;
           p->parent=y;
     }
};
void AVLtree::rightrotate(Node *p)
{
     if(p->left==NULL)
          return ;
     else
     {
         Node *y=p->left;
         if(y->right!=NULL)
         {
                  p->left=y->right;
                  y->right->parent=p;
         }
         else
                 p->left=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root=y;
         else
         {
             if(p==p->parent->left)
                   p->parent->left=y;
             else
                   p->parent->right=y;
         }
         y->right=p;
         p->parent=y;
     }
};



int AVLtree::search(int x)
{
     if(root==NULL)
     {
           cout<<"\nEmpty Tree\n" ;
           return  -1;
     }
    
     Node *p=root;
     int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key==x)
                found=1;
            if(found==0)
            {
                 if(p->key<x)
                      p=p->right;
                 else
                      p=p->left;
            }
         
     }
  
     if(found==0)
         return -1;
     else
     {
     	return p->key;
     }
};






///////////////////////////// functions ///////////////////////////////////////////
int menu()
{
	int e;
	do {
	
		cout<<"1. Load hotels and reservatios from file"<<endl;
		cout<<"2. Save hotels and reservatios to file"<<endl;
		cout<<"3. Add a hotel"<<endl;
		cout<<"4. Search and Display a hotel by id"<<endl;
		cout<<"5. Display all hotels of specific stars_hotel category and number of reservation"<<endl;
		cout<<"6. Display reservations by surname search"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"Pleas Give your Choice:";
		cin >>e;
	}  while (e<0 || e>7);
		return e;
	
	
};




int openCSV(char filename[200])
{
	
	ifstream file;
	char c;
	int NRows=1000;
	string column[100];
		int i,j,k,l;
	string s1,s2;
	int N=0;
	
	file.open(filename);
	k=-1;
    while(!file.eof() && k<NRows)
	{
				s2="";
				i=0;
				getline(file,s1);
				for (j=0;j<s1.length();j++)
				{
					if(s1.at(j)!=';')	s2=s2+s1.at(j);
					if(s1.at(j)==';') {	column[i]=s2;s2="";	i++;	}
				}
				column[i]=s2; i++;
			
				if(k==-1)
				{
					N=atoi(column[0].c_str());
					TableData=(HOTEL * ) malloc(N*sizeof(HOTEL));
				}
				else
				{
					
					RESV *KK= (RESV * ) malloc( (i-4)/3*sizeof(RESV));
					int l=4;
					for (int j=0;j<(i-4)/3;j++)
					{
						KK[j].set(column[l].c_str(), column[l+1].c_str(),atoi(column[l+2].c_str()));
						l+=3;
					}
					TableData[k].set(atoi(column[0].c_str()), column[1].c_str(),atoi(column[2].c_str()),atoi(column[3].c_str()),KK, (i-4)/3 );
					
				}
				k++;
				
								
				
			}
		N=k;	
		file.close();
	
	
}



