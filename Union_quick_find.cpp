/**** This is the implementation of the Union by Quick find  , Path compression does not workk in it
Its prity expensive , so its used very less in the code 
*****/
#include<iostream>
using namespace std;
const int MAX = 1000;

class UnionQuickFind 
{ 
	int U[MAX] ;
	void child_to_parent(int u);
	public :
		UnionQuickFind() ;
		int  find(int u) ;
		bool Union(int u,int v) ;
		void display() ;
};

UnionQuickFind::UnionQuickFind()   /// 		it is like Make process      self pointing 
{
			for(int i = 0 ; i < MAX ; i++)
				U[i]  = i ;
}

int UnionQuickFind::find(int u)
{
	if(u < 0 && u > MAX)
		{			
			return -1;
		}
	if(U[u] == u)
		return u ;
}

bool UnionQuickFind::Union(int u,int v)
{
	int r1 , r2 ;
	r1 = find(u) ;
	r2 = find(v) ;
	if(r1 == -1 || r2 == -1){
		cout << "Boundary Error" ;
		return false ;
	}	
	if(r1 == r2)
		return false ;
	
	/**** Seting the parents , in the QuickFind ***/
	for(int i  = 0 ; i < 11 ; i++)
	{
		if(U[i] == r2 )
		   U[i] = r1 ;
	}
	U[r2] = U[r1] ;
	return true ;
}

void UnionQuickFind::display()
{
	for(int i  = 0 ; i < 11 ; i++)
	{
		child_to_parent(i) ;
		cout<< "\n\n" ;
	}
}

void UnionQuickFind::child_to_parent(int u)
{
	cout<< u ; 
	if(U[u] == u)
		return ;
	cout << " --->>"; 	
	child_to_parent(U[u]) ;
}
int main()
{
	UnionQuickFind obj ;
	obj.Union(1,2);
	obj.Union(1,3);
	obj.Union(4,5);
	obj.Union(1,5);
	obj.Union(6,7);
	obj.Union(6,8);
	obj.Union(9,10);
	obj.Union(8,9);
	obj.Union(8,1);
	obj.display() ;
}
