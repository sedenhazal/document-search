#include "search.cpp"
#include <gtest/gtest.h>

TEST(SearchModuleTest, comparison)
{

	vector <string> goldenresult;
	string word = "cat";

	goldenresult.push_back("library/animals/cats/doc1.txt 3");
	goldenresult.push_back("library/animals/cats/doc2.txt 1");
	
	ASSERT_EQ( goldenresult, search(word) );
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
