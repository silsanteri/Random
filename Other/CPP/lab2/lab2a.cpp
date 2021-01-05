// Exercise 2A

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(const string &xml, string tag_name);

int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}

	location = find_field(page, "location");
	temperature = find_field(page, "temp_c");
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl;
}

string find_field(const string &xml, string tag_name)
{
	string tag1 = "<" + tag_name + ">";
	string tag2 = "</" + tag_name + ">";

	if(xml.find(tag1) != string::npos){
		size_t firstIndex = xml.find(tag1) + tag1.length();
		size_t lastIndex = xml.find(tag2) - firstIndex;

		return xml.substr(firstIndex, lastIndex);
	} else {
		return "not found";
	}
}