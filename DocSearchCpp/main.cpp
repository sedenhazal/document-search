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
#include <experimental/filesystem>

using namespace std;


class DocumentSearch
{
  map<string,vector<int> > InvertedIndex; // map < word, FileID>

  public:
    void index(string filename);
    void search(string word);
    void print();
};

void DocumentSearch::index(string filename)
{

  vector<string> filelist;
  ifstream f;
  f.open(filename,ios::in);

  if(!f)
  {
    cout<<"File Not Found\n";
    return ;
  }

  filelist.push_back(filename);

  string line,word;
  int line_number=0;
  while(getline(f,line))
  {
    line_number++;
    stringstream s(line);
    while(s>>word)
    {
      InvertedIndex[word].push_back((int)filelist.size());
    }
  }
  f.close();

}

void DocumentSearch::print()
{
  string filename = "outfile.txt";
  ofstream outfile;
  outfile.open(filename,ios::out);

  for(auto it = InvertedIndex.begin(); it != InvertedIndex.end(); ++it)
  {
	  outfile << it->first << " : ";

      for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
      {
    	  outfile << *it2 << " ";
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
			Data.index(argv[2]);
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







