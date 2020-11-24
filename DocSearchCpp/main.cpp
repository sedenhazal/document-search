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
#include <algorithm>
#include <bits/stdc++.h>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;


class DocumentSearch
{
  map<string,vector<int> > InvertedIndex; // map <word,fileID>
  vector< vector<int> > frequency; // vector<word,frequency>
  vector<string> filelist;

  public:
    void analyzer(string directory);
    void merge();
    void index();
    void search(string word);
    void print();
};

void DocumentSearch::analyzer(string directory)
{
    for(auto& p: fs::recursive_directory_iterator(directory))
    {
    	filelist.push_back(p.path());
    }

	//fs::remove_all(directory);

}

void DocumentSearch::index()
{

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
		int line_number=0;
		while(getline(f,line))
		{
			line_number++;
			stringstream s(line);
			while(s>>word)
			{
				InvertedIndex[word].push_back(i);
			}
		}
		f.close();
	}

}

void DocumentSearch::merge()
{
	  int freq = 1;
	  int ind = 0;

	  cout << InvertedIndex.size()<< endl;
	  //frequency.resize(InvertedIndex.size());

	  for(auto it = InvertedIndex.begin(); it != InvertedIndex.end(); ++it)
	  {
		vector<int>& v = it->second;
		vector<int> vfreq;

		  // Calculate number of occurrences.
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
		    		  vfreq.push_back(freq);
		    		  freq = 1; // reset frequency

		    		  if(j == (int)v.size() - 1)
		    		  {
		    			  vfreq.push_back(freq);
		    		  }
		    	  }
		      }

		      if (freq > 1)
		      {
		    	  vfreq.push_back(freq);
		    	  freq = 1; // reset frequency
		      }
	      }
	      else
	      {
	    	  vfreq.push_back(freq);
	      }

    	  //frequency[ind].resize(vfreq.size());
    	  frequency.push_back(vfreq);

		  cout << ind + 1 << " : ";
		  for (int k = 0; k < (int)frequency[ind].size(); k++)
		  {
			 cout << frequency[ind][k] << " ";
		  }
		  cout << endl;

	      // Delete duplicates.
		  unordered_set<int> s(v.begin(), v.end());
		  v.assign(s.begin(), s.end());
		  reverse(v.begin(), v.end());

    	  ind++;
	  }

	  // Print
	  string filename = "outfile.txt";
	  ofstream outfile;
	  outfile.open(filename,ios::out);

	  int ind1, ind2 = 0;
	  for(auto it = InvertedIndex.begin(); it != InvertedIndex.end(); ++it)
	  {

		  outfile << it->first << " : ";

		  ind2 = 0;
	      for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
	      {
	    	  outfile << *it2 << "-" << frequency[ind1][ind2] <<" ";
	    	  ind2++;

	      }
	      outfile << endl;
		  ind1++;
	  }

	  outfile.close();

}

void DocumentSearch::print()
{
  string filename = "outfile.txt";
  ofstream outfile;
  outfile.open(filename,ios::out);

  int ind, ind2 = 0;
  for(auto it = InvertedIndex.begin(); it != InvertedIndex.end(); ++it)
  {
	  ind++;
	  outfile << it->first << " : ";

	  ind2 = 0;
      for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
      {
    	  ind2++;
    	  outfile << *it2 <<" ";

      }
      outfile << endl;
  }

  outfile.close();

}

void DocumentSearch::search(string word)
{
	if(InvertedIndex.find(word)== InvertedIndex.end())
	{
	cout<<"No instance exist\n";
	return ;
	}

	int size = (int)InvertedIndex.size();
	for(int counter = 0;counter < size ;counter++)
	{
	cout<<counter+1<<":\n";
	cout<<" FileID: "<<InvertedIndex[word][counter]<<endl;
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
		Data.merge();
		//Data.print();
	}
	else if (command == "-search")
	{
		Data.search(argv[2]);
	}
	else
	{
		cout << "Undefined command!";
	}

  return 0;
}







