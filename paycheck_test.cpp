#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  char prevchar;
  char currchar;
  int count;
  string filename;
  ifstream infile;

  cout << "Enter the name of a file (or \"quit\"): ";
  cin >> filename;

  while (filename != "quit") {

    infile.open(filename);
    // infile.open(filename.c_str());  This syntax required in older (before 2011) C++ standards.
    if (!infile) {
      cout << "couldn't open file." << endl;
    } else {
      count = 0;
      infile.get(prevchar);
      infile.get(currchar);
      while (infile) {
        if (prevchar == '>' && currchar == '=') {
          count++;
        }

        prevchar = currchar;
        infile.get(currchar);
      }
    }

    infile.clear();
    infile.close();
    cout << "It occured " << count << " times." << endl;

    cout << "Enter the name of a file (or \"quit\"): ";
    cin >> filename;
  }
}
