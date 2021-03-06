#include <string>
#include <vector>
#include <cstddef>

#include "tinytest.h"

void Split(const std::string& src,
           const std::string& delim,
           std::vector<std::string>& v)
{
  std::size_t spos = 0;
  std::size_t epos = src.find(delim);
  std::size_t size = src.size();
  while ( spos != std::string::npos && spos < size )
  {
    if ( epos != std::string::npos )
    {
      v.push_back(src.substr(spos, epos-spos));
      spos = epos + delim.size();
      epos = spos < size ? src.find(delim, spos) : std::string::npos;
    }
    else
    {
      v.push_back(src.substr(spos));
      spos = epos;
    }
  }
}

int SplitTest1(const char *pName)
{
  std::vector<std::string> v;
  Split("jjj 1111 222", " ", v);
  TINYTEST_ASSERT((v.size() == 3));
  TINYTEST_ASSERT((v[0] == "jjj"));
  TINYTEST_ASSERT((v[1] == "1111"));
  TINYTEST_ASSERT((v[2] == "222"));
  return 1;
}

int SplitTest2(const char *pName)
{
  std::vector<std::string> v;
  Split("", " ", v);
  TINYTEST_ASSERT((v.empty()));
  return 1;
}

int SplitTest3(const char *pName)
{
  std::vector<std::string> v;
  Split("111", " ", v);
  TINYTEST_ASSERT((v.size() == 1));
  return 1;
}

TINYTEST_START_SUITE(SplitSuite);
  TINYTEST_ADD_TEST(SplitTest1,NULL,NULL);
  TINYTEST_ADD_TEST(SplitTest2,NULL,NULL);
  TINYTEST_ADD_TEST(SplitTest3,NULL,NULL);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(SplitSuite);

