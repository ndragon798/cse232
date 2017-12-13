#ifndef MAP_KNN
#define MAP_KNN

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
using std::ostream;
#include<utility>
using std::pair;

vector<string> split(const string &s, char delim);
void read_data(map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf);
string pair_to_string(const pair<vector<double>, string> &p);
void print_map(const map<vector<double>, string> &m, ostream &out);
double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count);
map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k);
double test_one(const map<vector<double>, string> &m, pair<vector<double>, string> test, int k);
double test_all(const map<vector<double>, string> &m, int k);

#endif
