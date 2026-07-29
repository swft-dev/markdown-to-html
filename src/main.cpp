#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    using std::cout;
    using std::cin;
    using std::getline;
    using std::vector;
    using std::string;
    using std::ofstream;
    using std::ifstream;
    
    string fileName{};

    cout << "Enter markdown file name (without extension):\n  >_";
    getline(cin, fileName);

    ifstream mdFile(fileName + ".md");
    ofstream htmlFile("output.html");

    if (!mdFile.is_open()) { 
        cout << "Error opening markdown file. Make sure it exists!\n"; 
        return 1;
    }
    if (!htmlFile.is_open()) { 
        cout << "Error opening html file.\n"; 
        return 1;
    }

    string line{};

    while (getline(mdFile, line)) {
        if (line.rfind("###", 0) == 0) { 
            htmlFile << "<h3>" + line.substr(4) + "</h3>\n"; 
        }
        else if (line.rfind("##", 0) == 0) { 
            htmlFile << "<h2>" + line.substr(3) + "</h2>\n"; 
        }
        else if (line.rfind("#", 0) == 0) { 
            htmlFile << "<h1>" + line.substr(2) + "</h1>\n"; 
        }
    }

    htmlFile << line;
    return 0;
}