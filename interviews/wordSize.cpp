#include<bits/stdc++.h>
using namespace std;

int sizeOfFinalWord(string line)
{
	string word;
	for(auto val : line)
	{
		if(val == ' ')
			word="";
		else
			word+=val;
	}
	return word.length();
}