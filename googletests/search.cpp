#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

vector<string> search(string word)
{
	string result;
	vector<string> total_result;

	// Read Inverted Index
	// Read from file.
		ifstream f;
		f.open("outfile.txt",ios::in);

		if(!f)
		{
			cout<<"File Not Found\n";
			return total_result;
		}

		string line;
		vector <string> tokens;
		while(getline(f,line))
		{
			stringstream check1(line);
			string intermediate;

			while(getline(check1, intermediate, ':'))
			{
				tokens.push_back(intermediate);
			}

		}
		f.close();

		  if(find(tokens.begin(), tokens.end(), word) == tokens.end())
		  {
		    cout<<"No instance exist\n";
		    return total_result;
		  }


		// Search for a given word.
		int position =  find(tokens.begin(), tokens.end(), word) - tokens.begin();
		stringstream check2(tokens[position + 1]);
		string intermediate2;
		vector <string> tokens2;
		while(getline(check2, intermediate2, ' '))
		{
			tokens2.push_back(intermediate2);
		}


		for(int i = 0; i < (int)tokens2.size(); i++)
		{
			stringstream check3(tokens2[i]);
			string intermediate3;
			vector <string> tokens3;
			while(getline(check3, intermediate3, '-'))
			{
				tokens3.push_back(intermediate3);

			}
			result = tokens3[0]+ " "+tokens3[1];
			cout << result << endl;

			total_result.push_back(result);
		}

		return total_result;
}
