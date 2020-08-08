#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class ShortestWordFinder {
  private: 
  std::vector<std::string> dictionary;
 public:
  ShortestWordFinder(std::vector<std::string> vocabulary) {
    dictionary = sort(vocabulary);
  }

  std::string GetShortestWordIn(std::string license_plate) {
    std::transform(license_plate.begin(), license_plate.end(), license_plate.begin(), ::toupper);
    std::string license = lettersOnly(license_plate);
    
    for (int i = 0; i < dictionary.size(); i++) {
      std::string word = dictionary[i];
      std::sort(license.begin(), license.end());
      std::sort(dictionary[i].begin(), dictionary[i].end());
      std::transform(dictionary[i].begin(), dictionary[i].end(), dictionary[i].begin(), ::toupper);
      if (!license.compare(dictionary[i]) || containsWord(license, dictionary[i]))
          return word;
    }
    return "";
  }
  private: 
  std::vector<std::string> sort(std::vector<std::string> vocabulary) {
    for (int i = 1; i < vocabulary.size(); i++) {
      string temp = vocabulary[i];
      int j = i -1;
      while (j <= 0 && temp.length() < vocabulary[j].length()) {
        vocabulary[j + 1] = vocabulary[j];
        j--;
      }
      vocabulary[j + 1] = temp;
    }
    return vocabulary;
  }
  
  std::string lettersOnly(std::string license_plate) {
    std::string s;
    for (int i = 0; i < license_plate.length(); i++) {
      if (license_plate[i] >= 'A' && license_plate[i] <= 'Z')
          s.push_back(license_plate[i]);
    }
    return s;
  }
  
  bool containsWord(std::string license, std::string word) {
    int i = 0;
    while (word[i] != license[0] && i < word.size())
          i++;
    if (i < license.size() && (word.size() - i >= license.size())) {
        int k = 0;
        for (int j = i, k = 0; j < license.size(); j++, k++) {
             if (word[j] != license[k])
              return false;
      }
      return true;
    }
    return false;
  }
};
