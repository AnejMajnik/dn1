#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void rearrangeA(vector<unsigned char>& A, const vector<int>& indices){
    vector<unsigned char> temp(A.size());
    for(int i=0; i<A.size(); i++){
        temp[i] = A[indices[i]];
    }
    A = temp;
}

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

void binaryRadixSort(vector<unsigned char>& A){
    vector<unsigned char> D(A.size());

    for(int k=0; k<8; k++){
        extractBits(A, D, k);
        vector<int> indices(A.size());
        iota(indices.begin(), indices.end(), 0);

        stable_sort(indices.begin(), indices.end(), [&](int i, int j){
            return D[i] < D[j];
        });

        rearrangeA(A, indices);
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

    binaryRadixSort(A);

    return 0;
}