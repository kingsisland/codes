#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> MaxSlices(int M, vector<int> slices, vector<vector<vector<int> > > dp, int n)
{	

	vector<int> selection;
	if(n==0 || M==0)
		return selection;

	if(dp[n][M].size() >0) return dp[n][M];   // returns calculated dp


	if(slices[n-1] > M)
	{
		dp[n][M] =MaxSlices(M,slices, dp, n-1);
		return dp[n][M];
	}

	vector<int> incN = MaxSlices(M-slices[n-1], slices, dp, n-1);
	vector<int> excN = MaxSlices(M, slices, dp, n-1);
	int sum_inc = slices[n-1],sum_exc=0;

	for(int i=0; i< incN.size(); i++)
		sum_inc+=slices[incN[i]];

	for(int i=0; i< excN.size(); i++)
		sum_exc+=slices[excN[i]];

	if( max(sum_inc,sum_exc)== sum_inc)
	{	incN.pb(n-1);
		dp[n][M] =incN ;
		
	}
	else
	{
		dp[n][M] = excN;

	}

	return dp[n][M];
}
 

int main(int argc, char** argv)
{	
	
	string inpFileName= argv[1], outFileName = argv[2];
	fstream inputFile;
	int M,N;
	
	inputFile.open(inpFileName.c_str());
	inputFile>>M;
	inputFile>>N;
	
	//vector<int> dp[N+1][M+1];
	vector<vector<vector<int> > > dp(N+1, vector<vector<int> >(M+1));
	// //checking 
	//cout<<M<<"	"<<N<<endl;

	vector<int> slices(N);
	for(int i=0; i<N; i++)
		inputFile>>slices[i];

	inputFile.close();
	//checking slices
	// for(int i=0; i<N; i++)
	// 	cout<<slices[i]<<" ";
	// cout<<endl;

	vector<int> selected = MaxSlices(M,slices,dp, N);
	// for(int i=0; i< selected.size(); i++)
	// 	cout<<selected[i]<<" ";
	// cout<<endl;

	ofstream outFile(outFileName.c_str());
	if(outFile.is_open())
	{
		outFile<<to_string(selected.size())+"\n";
		for(int i=0; i< selected.size(); i++)
			outFile<<to_string(selected[i])+" ";
		outFile<<'\n';
		outFile.close();
	}


	return 0;
}