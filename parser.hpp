// parser.hpp

#include <iostream>
#include <fstream>
#include <string>
#include <boost/unordered_map.hpp>
#include <boost/container/map.hpp>
#include <boost/container/list.hpp>
#include <boost/tokenizer.hpp>
#include "hikedatafsm.hpp"

using namespace std;

class HikeData {
  private:
    string file;
    string line;
    ifstream hdStream;
  public:
    HikeData(string fileName) : file(fileName), hdStream(fileName) {};

    void Parser(void) {
      typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
      boost::char_separator<char> del{" ", ":-"};
      HikeDataFSM hdFsm;

      if (hdStream.is_open()) {
        while (getline(hdStream, line)) {
          tokenizer tokens(line, del);
          for (const auto &token : tokens)
            hdFsm.performActions(token);
        }
      }
    }

    void PrintHikeData(void) {
        if (hdStream.is_open()) {
	  while (getline(hdStream, line)) {
            cout << line << endl;
          }
          hdStream.close();
        }
	else
	  cerr << "Unable to open file " << file << endl;
    }

};

