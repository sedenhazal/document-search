/*
 * main.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: hazalg
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <experimental/filesystem>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;
namespace fs = std::experimental::filesystem;

struct file
{
	string FileName;
	int frequency;

	private:
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version)
		{
		   ar & FileName;
		   ar & frequency;
		}
};

class DocumentSearch
{

  map<string,vector<int> > InvertedIndexTemp; // map <word,fileID>
  map<string,vector<file> > InvertedIndex; // map <word,file>
  vector<string> filelist;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive& ar, const unsigned version)
  {
  	  ar & InvertedIndex;
  }

  public:
    void analyzer(string directory);
    void index();
    void search(string word);

};


void DocumentSearch::analyzer(string directory)
{
	for(auto& p: fs::recursive_directory_iterator(directory))
	{
		filelist.push_back(p.path());
    }
}

void DocumentSearch::index()
{
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

void DocumentSearch::search(string word)
{
	map<string,vector<file> > RestoredInvertedIndex; // map <word,file>

	// Read Inverted Index
	// Read from file.
		ifstream f;
		f.open("outfile.txt",ios::in);

		if(!f)
		{
			cout<<"File Not Found\n";
			return ;
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
		    return ;
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
			cout << tokens3[0] << " " << tokens3[1] << endl;
		}


}

int main(int argc, char*argv[])
{
	DocumentSearch Data;

	string command = argv[1];

	if (command == "-index")
	{
		Data.analyzer(argv[2]);
		Data.index();
		//Data.merge();
	}
	else if (command == "-search")
	{
		cout << "Searching for '" << argv[2] << "' : " << endl;
		Data.search(argv[2]);
	}
	else
	{
		cout << "Undefined command!";
	}

  return 0;
}







