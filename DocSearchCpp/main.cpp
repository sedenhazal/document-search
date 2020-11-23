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
  map<string,vector<int> > InvertedIndex; // map < word,fileID>
  vector<string> filelist;
  vector<int> frequency; // number of occurrences.

  public:
    void analyzer(string directory);
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

  // delete duplicated fileIDs.
  map<int, int> duplicates;
  for(auto it = InvertedIndex.begin(); it != InvertedIndex.end(); ++it)
  {
	  vector<int>& v = it->second; // fileID

	  // Determine the number of occurrences.
	  for (auto & elem: v)
	  {
		  auto result = duplicates.insert(pair<int,int>(elem,1));
		  if (result.second == false)
			  result.first->second++;
	  }


	  for (auto & elem: duplicates)
	  {
		  frequency.push_back(elem.second);
	  }

	  unordered_set<int> s(v.begin(), v.end());
	  v.assign(s.begin(), s.end());

  }

}

void DocumentSearch::print()
{
  string filename = "outfile.txt";
  ofstream outfile;
  outfile.open(filename,ios::out);


  for(auto it = InvertedIndex.begin(); it != InvertedIndex.end(); ++it)
  {
	  outfile << it->first << " : ";

	  int ind = 0;
      for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
      {
    	  outfile << *it2 << "-"<< frequency[ind] <<" ";
    	  ind++;
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
			Data.print();
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







