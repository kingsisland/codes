#include <bits/stdc++.h>
using namespace std;

int main()
{	string path = "file.txt", outpath="outfile.txt";
	ifstream file(path);
	string line,word;
	vector< vector<string> > formatted;
	//int row =-1, col= -1;
	while(getline(file, line))
	{	//row++;
		// Line contains a row in this instant
		int p = 0;
		//while( line[p] == ' '  && p < line.length()) p++;
		vector<string> words;
		while(p < line.length()){
			if(line[p] == ' ')
			{
				//col++;
				words.push_back(word);
				word = "";

			}
			else
				word.push_back(line[p]);
			p++;
		}
		words.push_back(word);
		word = "";
		formatted.push_back(words);

	}
	file.close();

	//ofstream outfile(outpath);
	//if (outfile.is_open())
	//{
		for( int j=0; j< formatted[0].size(); j++)
		{	
			//outfile<<formatted[0][j];
			cout<<formatted[0][j];
			for(int i =1; i< formatted.size(); i++)
			{	
				// outfile<<" ";
				// outfile<<formatted[i][j];
				cout<<" "<<formatted[i][j];
				
			}
			// outfile<<"\n";
			cout<<"\n";

		}
		//outfile.close();
	//}
	


	return 0;
}