#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#pragma warning(disable:4996)

class CompareWords {
public:
	bool operator ()(const std::pair<std::string, int>& t1, const std::pair<std::string, int>& t2) {
		if (t1.second == t2.second) {
			if (strcmp(t1.first.c_str(), t2.first.c_str()) > 0)
				return true;
		}
		return t1.second < t2.second;
	}

};

void readTextFromFile(std::string &text) {
	std::ifstream read("date.in");
	std::istream& getline(std::istream & is, std::string & str);
	std::getline(read, text);

	std::transform(text.begin(), text.end(), text.begin(), //convert string to lowercase
		[](unsigned char c) { return std::tolower(c); });
}


std::map<std::string, int> splitTextAndCreateWordsMap(std::string text){
	std::map<std::string, int> words;
	char* token = strtok((char*)(text.c_str()), " ,?!.");
	while (token != NULL){
		if (words.find(token) == words.end()) {
			words.insert(std::pair<std::string, int>(token, 1));
		}else{
			words.at(token)++;
		}
		token = strtok(NULL, " ,?!.");
	}
	return words;
}


void printMap(std::map<std::string, int> myMap) {
	std::cout << "{\n";
	for (std::map<std::string, int>::const_iterator it = myMap.begin(); it != myMap.end(); ++it){
		std::cout << "\t "<< it->first << " : " << it->second << "\n";
	}
	std::cout << "}\n";
}


void print_pqueue(std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, CompareWords> pq) {
	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, CompareWords> copy_q = pq;
	while (!copy_q.empty()) {
		std::cout << copy_q.top().first << " => " << copy_q.top().second << std::endl;
		copy_q.pop();
	}
}

int main(){
	std::string text;
	readTextFromFile(text);
	//std::cout << text.c_str() << std::endl;

	std::map<std::string, int> words = splitTextAndCreateWordsMap(text);
	//printMap(words);

	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, CompareWords> sortedWords;
	
	for (std::map<std::string, int>::const_iterator it = words.begin(); it != words.end(); ++it){
		sortedWords.push(std::pair<std::string, int>(it->first, it->second));
	}

	print_pqueue(sortedWords);
}