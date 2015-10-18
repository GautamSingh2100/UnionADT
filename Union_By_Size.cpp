	/**** Union by size functionality is checked ****/
	/**** Test caes passed , can trust the implementation ****/
	/**** UT - Passed ****/

	#include<iostream>
	using namespace std;
	const int MAX = 1000;
	// note that path comprasion not applicable over the union by the height
	class UnionQuickFind 
	{ 
		int U[MAX] ;
		void child_to_parent(int u);
		public :
	
			UnionQuickFind()   /// 		it is like Make process      self pointing 
			{
				for(int i = 0 ; i < MAX ; i++)
					U[i]  = -1 ;
			}

			int find(int u) ;
			bool	Union(int u,int v) ;
			void display() ;
	};

	int UnionQuickFind::find(int u)
	{
		if(u < 0 && u > MAX)
			{			
				return -1;
			}
		if(U[u] < 0)
			return u ;
		
		return  find(U[u]) ;
	}

	bool UnionQuickFind::Union(int u,int v)
	{
		int r1 , r2 ;
		r1 = find(u) ;
		r2 = find(v) ;
		if(r1 == -1 || r2 == -1){
			cout << "boundary error" ;
			return false ;
		}	
		if(r1 == r2)
			return false ;
		if(U[r1] > U[r2])
		{
			U[r2] = U[r2] + U[r1] ; 
			U[r1] = r2 ;
		}
		else
		{
			U[r1] += U[r2]	 ;
			U[r2] = r1  ;
		}
	
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
		cout<< u;
		if(U[u] < 0)
		{
			//cout << "size" << U[u] ;
			return ;
		}
		cout <<  "   --->>"; 
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
		cout<< endl ;
		obj.display() ;
	}
