using namespace std;
#include <iostream>
#include <fstream>
#include <vector>

void printArr(const vector<unsigned char> arr){
    for(size_t i=0; i<arr.size(); i++){
        cout << static_cast<int>(arr[i]) << " ";
    }
}

void extractBits(const vector<unsigned char>& A, vector<unsigned char>& D, int k){
    D.clear();
    for(size_t i=0; i<A.size(); i++){
        D.push_back((A[i] >> k) & 1);
    }
}

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
    while(inputFile >> number){
        if(number < 0 || number > 255){
            cerr << "Število izven ranga";
            return 1;
        }
        A.push_back(static_cast<unsigned char>(number));
    }
    inputFile.close();

    vector<unsigned char> D;
    extractBits(A, D, 0);
    printArr(D);
    
}