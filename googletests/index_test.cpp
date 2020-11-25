#include "index.cpp"
#include <gtest/gtest.h>

TEST(IndexModuleTest, comparison)
{
 	std::ifstream t("golden_result.txt");
 	std::string goldenresult((std::istreambuf_iterator<char>(t)),
                      std::istreambuf_iterator<char>());

	vector <string> filelist;
	filelist.push_back("library/animals");
	filelist.push_back("library/animals/dogs");
	filelist.push_back("library/animals/dogs/doc1.txt");
	filelist.push_back("library/animals/dogs/doc2.txt");
	filelist.push_back("library/animals/cats");
	filelist.push_back("library/animals/cats/doc1.txt");
	filelist.push_back("library/animals/cats/doc2.txt");
	filelist.push_back("library/history");
	filelist.push_back("library/history/europe");
	filelist.push_back("library/history/europe/turkey.txt");
	filelist.push_back("library/history/asia");
	filelist.push_back("library/history/asia/china.txt");


	index(filelist);

	std::ifstream t2("outfile.txt");
 	std::string testresult((std::istreambuf_iterator<char>(t2)),
                      std::istreambuf_iterator<char>());

	ASSERT_EQ(goldenresult, testresult);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
