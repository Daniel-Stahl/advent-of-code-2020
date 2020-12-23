enum DataType { ecl, pid, eyr, hcl, byr, iyr, cid, hgt };

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile;
    string data;
    int valid = 0;
    
    
    inFile.open("/Users/stahl/Desktop/Projects/Advent Of Code 2020/AdventOfCode2020Day4/AdventOfCode2020Day4/data.txt");
    
//    if (!inFile) {
//        cout << "file not ready!";
//    }
    string temp;
    int count = 0;
    
    // ecl
    // pid
    // eyr
    // hcl
    // byr
    // iyr
    // cid
    // hgt
    
    // if data contains all of these then its valid
    // if data is only missing cid then its valid
    // if data is missing cid and andything elese then its invalid
    
    
    
    //bool foundCID = false;
    
    while (!inFile.eof()) {
        getline(inFile, data);
        
        if (data != "") {
            temp.append(data);
        } else {
            bool foundCID = false;
            
            for (int x = 0; x < temp.size(); x++) {
                if (temp[x] == ':') {
                    if (temp[x-3] == 'e' && temp[x-2] == 'c' && temp[x-1] == 'l') {
                        count++;
                    } else if (temp[x-3] == 'p' && temp[x-2] == 'i' && temp[x-1] == 'd') {
                        count++;
                    } else if (temp[x-3] == 'e' && temp[x-2] == 'y' && temp[x-1] == 'r') {
                        count++;
                    } else if (temp[x-3] == 'h' && temp[x-2] == 'c' && temp[x-1] == 'l') {
                        count++;
                    } else if (temp[x-3] == 'b' && temp[x-2] == 'y' && temp[x-1] == 'r') {
                        count++;
                    } else if (temp[x-3] == 'i' && temp[x-2] == 'y' && temp[x-1] == 'r') {
                        count++;
                    } else if (temp[x-3] == 'h' && temp[x-2] == 'g' && temp[x-1] == 't') {
                        count++;
                    } else if (temp[x-3] == 'c' && temp[x-2] == 'i' && temp[x-1] == 'd') {
                        count++;
                        foundCID = true;
                    } else {
                        foundCID = false;
                    }
                }
            }
            
            if (count == 8) {
                valid++;
            } else if(count == 7 && !foundCID) {
                valid++;
            }
            
            // ecl = 1
            // pid = 1
            // eyr = 1
            // hcl = 1
            // byr = 1
            // iyr = 1
            // cid = 1
            // hgt = 1
            
            // if data contains all of these then its valid = 8
            // if data is only missing cid then its valid = 7 && cid is missing
            // if data is missing cid and anything else then its invalid = 6
            
            count = 0;
            temp.erase();
        }
    }
    
    cout << "total = " << valid << endl;
}
