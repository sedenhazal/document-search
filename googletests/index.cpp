#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

struct file
{
	string FileName;
	int frequency;
};

void index(vector<string> &filelist)
{
	map<string,vector<int> > InvertedIndexTemp; // map <word,fileID>
	map<string,vector<file> > InvertedIndex; // map <word,file>
	vector<int> v1,v2;

	// 1. Construct Inverted Index
	for (int i = 0; i < (int)filelist.size(); i++)
	{
		ifstream f;
		f.open(filelist[i],ios::in);

		if(!f)
		{
			cout<<"File Not Found\n";
			return ;
		}

		string line,word;
		while(getline(f,line))
		{
			stringstream s(line);
			while(s>>word)
			{
				InvertedIndexTemp[word].push_back(i);
			}
		}
		f.close();
	}

	int freq = 1;
	int ind = 0;

	string filename = "outfile.txt";
	ofstream outfile;
	outfile.open(filename,ios::out);

	// 2. Create Inverted Index.
	for(auto it = InvertedIndexTemp.begin(); it != InvertedIndexTemp.end(); ++it)
	{
		string word = it->first;
		vector<int>& v = it->second;
		file obj;

		if ((int)v.size() > 1)
		{
			for (int j = 1; j < (int)v.size(); j++)
			{

				if (v[j] == v[j - 1])
				{
					freq++;
				}
				else
				{
					//obj.fileId = v[j - 1];
					obj.FileName = filelist[v[j - 1]];
					obj.frequency = freq;
					InvertedIndex[word].push_back(obj);
					freq = 1; // reset frequency

					// For the last vector element which is different from previous one.
					if(j == (int)v.size() - 1)
					{
						//obj.fileId = v[j];
						obj.FileName = filelist[v[j]];
						obj.frequency = freq;
						InvertedIndex[word].push_back(obj);
					}
				}
			}

			// For cases like: {1,1,1} or {1,1,1,2,2,2} etc.
			if (freq > 1)
			{
				//obj.fileId = v.front();
				obj.FileName = filelist[v.front()];
				obj.frequency = freq;
				InvertedIndex[word].push_back(obj);
				freq = 1; // reset frequency
			}
		}
		else
		{
			//obj.fileId = v.back();
			obj.FileName = filelist[v.back()];
			obj.frequency = freq;
			InvertedIndex[word].push_back(obj);
		}

		// 3. Print Inverted Index
		outfile <<  word << ":";
		cout << word << ":";

		int size = (int)InvertedIndex[word].size();
		for (int it2 = 0; it2 < size; it2++)
		{
			outfile << InvertedIndex[word][it2].FileName << "-" << InvertedIndex[word][it2].frequency << " ";
			cout << InvertedIndex[word][it2].FileName << "-" << InvertedIndex[word][it2].frequency << " ";
		}

		outfile << endl;
		cout << endl;
		ind++;

	}

	outfile.close();
}
