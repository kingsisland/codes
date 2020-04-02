#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ifstream inpFile(argv[1]);
	string line;
	if(inpFile.is_open())
	{
		while(getline(inpFile, line))
			cout<<line<<'\n';
		inpFile.close();
	}
	return 0;

}