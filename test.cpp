#include <iostream>
#include <string>
#include <pcrecpp.h>

using namespace std;

int main ()
{
  std::string s("miss");
  std::string result;
  pcrecpp::RE re("(s)$");
  re.Replace("(\\1)", &s);
  std::cout << s << std::endl;

    // try {
    //   std::regex e ("\(.)$");   // matches words beginning by "sub"
    //   std::cout << std::regex_replace(s,e, std::string("sub-$1"));
    // }catch(std::regex_error& e){
    //   std::cout << "Regex error code" << e.code() <<std::endl;
    // }

  // using range/c-string (6) version:
  // std::string result;
  // std::regex_replace (std::back_inserter(result), s.begin(), s.end(),
  //     e, "$2");
  // std::cout << result;
  //
  // // with flags:
  // std::cout << std::regex_replace (s,e,"$1 and
  //     $2",std::regex_constants::format_no_copy);
  // std::cout << std::endl;

  return 0;
}
