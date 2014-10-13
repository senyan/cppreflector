#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <pcrecpp.h>

using namespace std;

class Inflector
{
   private:
     vector<pair<string, string> >sing_rules;
     vector<pair<string, string> >plur_rules;
     vector<string>unaccountables;
     vector<pair<string, string> >irregulars;

   bool unaccountable(string* word) 
   {
      for(int i = 0; i < unaccountables.size(); i ++)
      {
        if(word -> compare( unaccountables[i]) == 0) { return true; }
      }
      return false;
   }

   int irr_check(string* word)
   {
      bool comp1 = false;
      bool comp2 = false;
      for(int i = 0; i < irregulars.size(); i ++)
      {
        comp1 = word -> compare(irregulars[i].second) == 0;
        comp2 = word -> compare(irregulars[i].first) == 0;
        if (comp1 || comp2)
        {
          return i;
        }
        comp1 = false;
        comp2 = false;
      }
      return -1;
   }

  void apply_rules(vector<pair<string, string> >* rules, string* word)
  {
    for(vector<pair<string, string> >::reverse_iterator it = rules -> rbegin(); it != rules -> rend(); it ++ )
    {
      pcrecpp::RE re((*it).first);
      if(re.Replace((*it).second, word))
      {
        break;
      }
    }
  };

   public:
    Inflector(){
      //Order of rules for each type matters
      sing_rules.push_back(make_pair("(s)$", ""));
      sing_rules.push_back(make_pair("(ss)$", "\\1"));
      sing_rules.push_back(make_pair("(n)ews$", "\\1ews"));
      sing_rules.push_back(make_pair("([ti])a$", "\\1um"));
      sing_rules.push_back(make_pair("((a)naly|(b)a|(d)iagno|(p)arenthe|(p)rogno|(s)ynop|(t)he)(sis|ses)$", "\\1sis"));
      sing_rules.push_back(make_pair("(^analy)(sis|ses)$", "\\1sis"));
      sing_rules.push_back(make_pair("([^f])ves$", "\\1fe"));
      sing_rules.push_back(make_pair("(hive)s$", "\\1"));
      sing_rules.push_back(make_pair("(tive)s$", "\\1"));
      sing_rules.push_back(make_pair("([lr])ves$", "\\1f"));
      sing_rules.push_back(make_pair("([^aeiouy]|qu)ies$", "\\1y"));
      sing_rules.push_back(make_pair("(s)eries$", "\\1eries"));
      sing_rules.push_back(make_pair("(m)ovies$", "\\1ovie"));
      sing_rules.push_back(make_pair("(x|ch|ss|sh)es$", "\\1"));
      sing_rules.push_back(make_pair("^(m|l)ice$", "\\1ouse"));
      sing_rules.push_back(make_pair("(bus)(es)?$", "\\1"));
      sing_rules.push_back(make_pair("(o)es$", "\\1"));
      sing_rules.push_back(make_pair("(shoe)s$", "\\1"));
      sing_rules.push_back(make_pair("(cris|test)(is|es)$", "\\1is"));
      sing_rules.push_back(make_pair("^(a)x[ie]s$", "\\1xis"));
      sing_rules.push_back(make_pair("(octop|vir)(us|i)$", "\\1us"));
      sing_rules.push_back(make_pair("(alias|status)(es)?$", "\\1"));
      sing_rules.push_back(make_pair("^(ox)en", "\\1"));
      sing_rules.push_back(make_pair("(vert|ind)ices$", "\\1ex"));
      sing_rules.push_back(make_pair("(matr)ices$", "\\1ix"));
      sing_rules.push_back(make_pair("(quiz)zes$", "\\1"));
      sing_rules.push_back(make_pair("(database)s$", "\\1"));

      plur_rules.push_back(make_pair("$", "s"));
      plur_rules.push_back(make_pair("s$", "s"));
      plur_rules.push_back(make_pair("^(ax|test)is$", "\1es"));
      plur_rules.push_back(make_pair("(octop|vir)us$", "\1i"));
      plur_rules.push_back(make_pair("(octop|vir)i$", "\1i"));
      plur_rules.push_back(make_pair("(alias|status)$", "\1es"));
      plur_rules.push_back(make_pair("(bu)s$", "\1ses"));
      plur_rules.push_back(make_pair("(buffal|tomat)o$", "\1oes"));
      plur_rules.push_back(make_pair("([ti])um$", "\1a"));
      plur_rules.push_back(make_pair("([ti])a$", "\1a"));
      plur_rules.push_back(make_pair("sis$", "ses"));
      plur_rules.push_back(make_pair("(?:([^f])fe|([lr])f)$", "\1\2ves"));
      plur_rules.push_back(make_pair("(hive)$", "\1s"));
      plur_rules.push_back(make_pair("([^aeiouy]|qu)y$", "\1ies"));
      plur_rules.push_back(make_pair("(x|ch|ss|sh)$", "\1es"));
      plur_rules.push_back(make_pair("(matr|vert|ind)(?:ix|ex)$", "\1ices"));
      plur_rules.push_back(make_pair("^(m|l)ouse$", "\1ice"));
      plur_rules.push_back(make_pair("^(m|l)ice$", "\1ice"));
      plur_rules.push_back(make_pair("^(ox)$", "\1en"));
      plur_rules.push_back(make_pair("^(oxen)$", "\1"));
      plur_rules.push_back(make_pair("(quiz)$", "\1zes"));

      unaccountables.push_back("equipment");
      unaccountables.push_back("information"); 
      unaccountables.push_back("rice"); 
      unaccountables.push_back("money"); 
      unaccountables.push_back("species"); 
      unaccountables.push_back("series"); 
      unaccountables.push_back("fish"); 
      unaccountables.push_back("sheep"); 
      unaccountables.push_back("jeans"); 
      unaccountables.push_back("police");

      irregulars.push_back(make_pair("person", "people"));
      irregulars.push_back(make_pair("man", "men"));
      irregulars.push_back(make_pair("child", "children"));
      irregulars.push_back(make_pair("sex", "sexes"));
      irregulars.push_back(make_pair("move", "moves"));
      irregulars.push_back(make_pair("zombie", "zombies"));
    };
    ~Inflector(){};


   string singularize(string word)
   {
    if (!unaccountable(&word)) 
    {
      int irr = irr_check(&word);
      if(irr >= 0){ return irregulars[irr].first; }
      apply_rules(&sing_rules, &word);
    }
    return string(word.c_str());
   };

   string pluralize(string word)
   {
    if (!unaccountable(&word)) 
    {
      int irr = irr_check(&word);
      if(!irr){ return irregulars[irr].second; }
      apply_rules(&plur_rules, &word);
    }
    return string(word.c_str());
   };

};

int main(){
  Inflector inflector;
  cout << "SINGULARIZE TESTING EXAMPLES: " << endl;
  cout << "books"   << "        " << inflector.singularize("books")<< endl;
  cout << "misses"  << "        " << inflector.singularize("misses")<< endl;
  cout << "goose"   << "        " << inflector.singularize("goose")<< endl;
  cout << "deers"   << "        " << inflector.singularize("deers")<< endl;
  cout << "workers" << "        " << inflector.singularize("workers")<< endl;
  cout << "people"  << "        " << inflector.singularize("people")<< endl;
  cout << "person"  << "        " << inflector.singularize("person")<< endl;

  cout << "PLURALIZE TESTING EXAMPLES: " << endl;
  cout << "workder" << "        " << inflector.pluralize("workder") << endl;
  cout << "deer"    << "        " << inflector.pluralize("deer") << endl;
  cout << "misses"  << "        " << inflector.pluralize("misses") << endl;
  cout << "person"  << "        " << inflector.pluralize("person") << endl;
  cout << "people"  << "        " << inflector.pluralize("people") << endl;
 
  cout << "UNACCOUNTABLE TESTING EXAMPLES: " << endl;
  cout << "information" << "          " << inflector.singularize("information") << endl;
  cout << "information" << "          " << inflector.pluralize("information") << endl;

  exit(1);
}
