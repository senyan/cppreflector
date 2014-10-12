#include <iostream>
#include <string>
#include <utility>
#include <regex>

using namespace std;

class Inflector
{
    static const int pluralize_rule_size = 21;
    static const int singularize_rule_size = 27;
  private:
     pair<string, string> pluralize_pattern_replacement[Inflector::pluralize_rule_size] =  {
      make_pair("$", "s"),
      make_pair("s$", "s"),
      make_pair("^(ax|test)is$", "\1es"),
      make_pair("(octop|vir)us$", "\1i"),
      make_pair("(octop|vir)i$", "\1i"),
      make_pair("(alias|status)$", "\1es"),
      make_pair("(bu)s$", "\1ses"),
      make_pair("(buffal|tomat)o$", "\1oes"),
      make_pair("([ti])um$", "\1a"),
      make_pair("([ti])a$", "\1a"),
      make_pair("sis$", "ses"),
      make_pair("(?:([^f])fe|([lr])f)$", "\1\2ves"),
      make_pair("(hive)$", "\1s"),
      make_pair("([^aeiouy]|qu)y$", "\1ies"),
      make_pair("(x|ch|ss|sh)$", "\1es"),
      make_pair("(matr|vert|ind)(?:ix|ex)$", "\1ices"),
      make_pair("^(m|l)ouse$", "\1ice"),
      make_pair("^(m|l)ice$", "\1ice"),
      make_pair("^(ox)$", "\1en"),
      make_pair("^(oxen)$", "\1"),
      make_pair("(quiz)$", "\1zes")
  };

    pair<string, string> singularize_pattern_replacement[Inflector::singularize_rule_size] =  {
      make_pair("(a|e|i|o|u)$", "")
      // make_pair("(ss)$", "\1"),
      // make_pair("(n)ews$", "\1ews"),
      // make_pair("([ti])a$", "\1um"),
      // make_pair("((a)naly|(b)a|(d)iagno|(p)arenthe|(p)rogno|(s)ynop|(t)he)(sis|ses)$", "\1sis"),
      // make_pair("(^analy)(sis|ses)$", "\1sis"),
      // make_pair("([^f])ves$", "\1fe"),
      // make_pair("(hive)s$", "\1"),
      // make_pair("(tive)s$", "\1"),
      // make_pair("([lr])ves$", "\1f"),
      // make_pair("([^aeiouy]|qu)ies$", "\1y"),
      // make_pair("(s)eries$", "\1eries"),
      // make_pair("(m)ovies$", "\1ovie"),
      // make_pair("(x|ch|ss|sh)es$", "\1"),
      // make_pair("^(m|l)ice$", "\1ouse"),
      // make_pair("(bus)(es)?$", "\1"),
      // make_pair("(o)es$", "\1"),
      // make_pair("(shoe)s$", "\1"),
      // make_pair("(cris|test)(is|es)$", "\1is"),
      // make_pair("^(a)x[ie]s$", "\1xis"),
      // make_pair("(octop|vir)(us|i)$", "\1us"),
      // make_pair("(alias|status)(es)?$", "\1"),
      // make_pair("^(ox)en", "\1"),
      // make_pair("(vert|ind)ices$", "\1ex"),
      // make_pair("(matr)ices$", "\1ix"),
      // make_pair("(quiz)zes$", "\1"),
      // make_pair("(database)s$", "\1")
  };

   public:
   string singularize(string word) {
     cout << word<<endl;
     // for(int i = 0; i < Inflector::singularize_rule_size; i ++)
     for(int i = 0; i < 1; i ++)
     {
       regex reg(singularize_pattern_replacement[i].first);
       // cout << singularize_pattern_replacement[i].first << endl;
       regex_replace(word, reg, string("alkfdjk"));
     }
     cout << word<<endl;

    return word;
  }
        Inflector(){};
        ~Inflector(){};
};

int main(){
  Inflector inflector;
  cout << inflector.singularize("boxes")<<endl;
  // cout << inflector.singularize("is")<<endl;
  // cout << inflector.singularize("miss")<<endl;
  // cout << inflector.singularize("s")<<endl;
  exit(1);
}




// inflect.irregular("person", "people")
// inflect.irregular("man", "men")
// inflect.irregular("child", "children")
// inflect.irregular("sex", "sexes")
// inflect.irregular("move", "moves")
// inflect.irregular("zombie", "zombies")
//
// inflect.uncountable(%w(equipment information rice money species series fish sheep jeans police))

