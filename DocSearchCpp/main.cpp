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
  vector<string> filelist;

  public:
    void index(string filename);
    void search(string word);
};

void DocumentSearch::index(string filename)
{
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
  for(int i = 1 ; i< argc ; i++)
  {
    Data.index(argv[i]);
  }

	cout<<"Enter Word: ";
	string word;
	cin>>word;
	Data.search(word);

  return 0;
}







