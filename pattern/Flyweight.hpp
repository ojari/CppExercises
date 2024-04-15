#pragma once
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;

struct Sentence {
  struct WordToken {
    bool capitalize;
    string text;

    WordToken(const string& word, bool capitalize = false) : 
        capitalize(capitalize), 
        text(word) 
    {}
  };

  Sentence(const string& text) {
    istringstream iss(text);
    string word;
    while (iss >> word) {
        WordToken wt {word, false};
        words.push_back(wt);
    }
  }

  WordToken& operator[](size_t index) {
    if (index >= words.size()) {
      throw out_of_range("index out of range");
    }
    return words[index];
  }

  string str() const {
    string result;
    bool first = true;
    for (auto word : words) {
      if (word.capitalize) {
        std::transform(word.text.begin(), word.text.end(), word.text.begin(), ::toupper);
      }
      if (!first) {  // do not add space before first word
        result += " ";
      }
      else {
        first = false;
      }
      result += word.text;
    }
    return result;
  }
private:
  vector<WordToken> words;
};