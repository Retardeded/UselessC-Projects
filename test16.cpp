#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int main(){
	
	int W;
	int n;
	cin >> W >> n;
	
	int * tab = new int[n];
    for (int i = 0; i < n; i++) 
	{
    cin >> tab[i];
    }
    
    long long ** prize = new long long *[n+1];
    for (int i = 0; i < n+1; i++)
    {
    	prize[i] = new long long [W+1];
	}
	for(int i = 0; i < W+1; i++)
	{
		prize[0][i] = 0;
	}
	for(int j = 0; j < n+1; j++)
	{
		prize[j][0] = 0;
	}
	int i;
	int j;
	for( i = 1; i < n+1; i++)
	{
		for( j = 1; j < W+1; j++)
		{
			if( (j-tab[i-1]) >= 0 && prize[i-1][j] < (prize[i-1][j-tab[i-1]] + tab[i-1]) )
			{
				prize[i][j] = prize[i-1][j-tab[i-1]] + tab[i-1];
			}
			else
			{
				prize[i][j] = prize[i-1][j];
			}
		}
	}
	for( i = 1; i < n+1; i++)
	{
		for(j = 1; j < W+1; j++)
		{
			cout << prize[i][j] << " ";
		}
		cout << endl;
	}
	cout << prize[n][W];
}
