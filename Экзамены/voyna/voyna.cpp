// voyna.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "assert.h"
#include "iostream"
#include "assert.h"

using namespace std;

int main()
{
	int n;

	cin >> n;
	assert(1<=n&&n<=104);
	int **S = new int *[n];
	for(int i=0;i<n;i++) S[i] = new int[3];
	int **F = new int *[n];
	for(int i=0;i<n;i++) F[i] = new int[3];

	char **Ss = new char *[n];
	for(int i=0;i<n;i++) Ss[i] = new char[9];
	char **Fs = new char *[n];
	for(int i=0;i<n;i++) Fs[i] = new char[9];

	int *k = new int[n];

	int *ans = new int[n];

	int *Sm = new int[n];
	int *Fm = new int[n];
	for(int i=0;i<n;i++) {
		cin >> Ss[i] >> Fs[i] >> k[i];
		assert(1<=k[i]&&k[i]<=2000);
	}

	for(int i=0;i<n;i++) {
		S[i][0] = (Ss[i][0] - '0')*10+(Ss[i][1] - '0');
		S[i][1] = (Ss[i][3] - '0')*10+(Ss[i][4] - '0');
		S[i][2] = (Ss[i][6] - '0')*10+(Ss[i][7] - '0');
		F[i][0] = (Fs[i][0] - '0')*10+(Fs[i][1] - '0');
		F[i][1] = (Fs[i][3] - '0')*10+(Fs[i][4] - '0');
		F[i][2] = (Fs[i][6] - '0')*10+(Fs[i][7] - '0');
	}

	for(int i=0;i<n;i++) {
		Sm[i] = S[i][0] * 3600 + S[i][1] * 60 + S[i][2];
		Fm[i] = F[i][0] * 3600 + F[i][1] * 60 + F[i][2];
		if(Fm[i]<Sm[i])
			ans[i] = Fm[i]-Sm[i]+86400-k[i]*60;
		else if(Fm[i]==Sm[i])
			ans[i]=86400-k[i]*60;
		else
			ans[i] = Fm[i]-Sm[i]-k[i]*60;

		if(ans[i]>=0)
			cout << "Perfect\n";
		else if((ans[i]+3600)>=0&&ans[i]<0)
			cout << "Test\n";
		else
			cout << "Fail\n";
	}
	
	system("pause");
	return 0;
}

