#include <bits/stdc++.h>
using namespace std;


int b, l, d;
vector <int> book_score, n, t, m;
vector<vector<int>>> id;	// id of books in each library
vector<double> scoresV1;
vector<double> scoresV2;	// Assigns scores to each lib based
								//on scoring function

bool compareV1(const int& libA, const int& libB)
{
	return scoresV1[libA] < scoresV1[libB];
}

vector <int> getLibSeqV1()		//avg score * signuptime {Wastage factor}
{	
	vector<int> libToSort; // initialize with 
							//initial library positions
	for(int i=0; i<l; i++)
		libToSort.push_back(i);
	
	for(int lib=0; lib<l; lib++)
	{
		int totScore=0;
		for(int j=0; j<n[lib]; j++)
			totScore+=   book_score[ id[lib][j] ];
		double days = ceil(n[lib] / m[lib]);
		double score = (totScore/days)*t[lib];
		scoresV1.push_back(score); 
	}

	sort(libToSort.begin(), libToSort.end(), compareV1);

	return libToSort;	
}




bool compareV2(const int& libA, const int& libB ){
	return scoresV2[libA] > scoreV2[libB];
}

vector<int> getLibSeqV2()    //strong to weak  // uses  sum of (score/frequency) divided by total time taken by that library
{
	vector<int> libToSort; // initialize with 
									//initial library positions
	for(int i=0; i<l; i++)
		libToSort.push_back(i);
	
	vector<int> bookFreq(b,0);
	
	for(int lib=0; lib< l; lib++)		// building freq array
	{
		for(int j=0; j < n[lib]; j++)
			bookFreq[ id[lib][j]] +=1;
	}

	for(int lib=0; lib<l; lib++)
	{	double libScore=0;
		for(int j=0; j < n[lib]; j++)
		{	int book_id = id[lib][j];
			libScore += book_score[book_id]/(bookFreq[ book_id ]);
		}
		double days = t[lib] + ceil( n[lib]/m[lib] );
		libScore = libScore/ days;
		scoresV2.push_back(libScore);

	}

	sort(libToSort.begin(), libToSort.end(), compareV2);
	return libToSort;



}





