# document-search

### Execute:

1. Directory of the exe is "document-search/DocSearchCpp/DocSearchCpp".

2. Linux terminal command to create InvertedIndex:
	./DocSearchCpp -index <path_to_library>

3. Linux terminal command to search for a word	
	./DocSearchCpp -search <some_word>

### Unit Test:
1. Directory of the unit test for index method: "document-search/googletests/executeIndexTest"
2. Directory of the unit test for search method: "document-search/googletests/executeSearchTest"

### Notes:

1. The program is written following object oriented programming structure. The program can be found under "document-search/main.cpp" directory.
2. There are 3 methods related to DocumentSearch class: analizer, index and search.
3. Unit tests are written for index and search methods. 
4. The InvertedIndex is defined using map data structure. Serialization/Deserialization for map couldn't be implemented. So, read/write functions are used instead. Because of that the search method is independent of InvertedIndex map data structure (it just reads data from txt file). 

### References:
1. https://www.youtube.com/watch?v=bnP6TsqyF30
2. https://github.com/JhaPrajjwal/Inverted-Index/blob/master/invertedindex.cpp
3. http://www.ocoudert.com/blog/2011/07/09/a-practical-guide-to-c-serialization/
4. https://en.cppreference.com/w/cpp/filesystem/recursive_directory_iterator
5. https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
6. https://www.srcmake.com/home/google-cpp-test-framework

	
