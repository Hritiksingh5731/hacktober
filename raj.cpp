
#include <bits/stdc++.h>
using namespace std;


void lcs(char* X, char* Y, int m, int n)
{
	int L[m + 1][n + 1];

	
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	
	int index = L[m][n];

	
	char lcs[index + 1];
	lcs[index] = '\0'; 

	
	int i = m, j = n;
	while (i > 0 && j > 0) {
		
		if (X[i - 1] == Y[j - 1]) {
			lcs[index - 1]
				= X[i - 1]; 
			i--;
			j--;
			index--;
		}

		
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	// Print the lcs
	cout << lcs;
  cout<<endl;
}


int main()
{
    int t;
    cin>>t;
   while(t--){ 
    int size;
    cin>>size;
    string s;
    cin>>s;
    string s2 = s;
    reverse(s.begin(),s.end());

    char X[size];
	char Y[size];
    for(int i=0;i<s.size();i++){
        X[i]=  s[i];
    }
    for(int i=0;i<s.size();i++){
        Y[i]=  s2[i];
    }
	
	lcs(X, Y, size, size);}
	return 0;
}
