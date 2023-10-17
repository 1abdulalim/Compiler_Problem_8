#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>

using namespace std;

unordered_map<string, string> tokenMap;


void initializeTokenMap() {
    // Keywords
    tokenMap["int"] = "Keyword";
    tokenMap["do"]="Keyword";
    tokenMap["float"] = "Keyword";
    tokenMap["double"] = "Keyword";
    tokenMap["char"] = "Keyword";
    tokenMap["if"] = "Keyword";
    tokenMap["else"] = "Keyword";
    tokenMap["while"] = "Keyword";
    tokenMap["for"] = "Keyword";

    // Arithmetic Operators
    tokenMap["+"] = "Arithmetic Operator";
    tokenMap["-"] = "Arithmetic Operator";
    tokenMap["*"] = "Arithmetic Operator";
    tokenMap["/"] = "Arithmetic Operator";
    tokenMap["%"] = "Arithmetic Operator";

    // Regular expression for float literals
    tokenMap["float_literal"] = "Float Literal";

    // Regular expression for integer literals
    tokenMap["integer_literal"] = "Integer Literal";

    // Default token for identifiers
    tokenMap["identifier"] = "Identifier";
}

string getCpPToken(const string& word) {
    if (tokenMap.find(word) != tokenMap.end()) {
        return tokenMap[word];
    } else if (regex_match(word, regex("^-?\\d+\\.\\d+$"))) {
        return tokenMap["float_literal"];
    } else if (regex_match(word, regex("^-?\\d+$"))) {
        return tokenMap["integer_literal"];
    } else {
        return tokenMap["identifier"];
    }
}

int main() {
    initializeTokenMap();
    for(int i=0;i<5;i++){
    string input_word;
    cout << "Enter a word: ";
    cin >> input_word;

    string token = getCpPToken(input_word);

    cout << input_word << " : " << token << endl;
    }
    return 0;
}
