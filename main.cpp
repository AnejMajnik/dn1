#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    //preveri če je pravo število podanih argumentov
    if(argc != 2){
        cerr << "Uporaba: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream inputFile(filename);

    if(!inputFile){
        cerr << "Napaka pri odpiranju datoteke" << endl;
        return 1;
    }

    int number;
    vector<unsigned char> A;

    inputFile.close();

}