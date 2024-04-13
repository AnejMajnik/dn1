#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "main.h"

using namespace std;

//Glede na indekse sortiranih bitov popravite vrstni red števil v A (tako velja i == j, za A[i] in D[j]).
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

//Od polja vhodnih števil A vzamite od vsakega števila k-ti bit (k je na začetku 0). Tako dobite polje bitov D.
void extractBits(const vector<unsigned char>& A, vector<unsigned char>& D, int k){
    D.clear();
    for(size_t i=0; i<A.size(); i++){
        D.push_back((A[i] >> k) & 1);
    }
}

void binaryRadixSort(vector<unsigned char>& A){
    vector<unsigned char> D(A.size());

    //Indeks k inkrementirate in se vrnete na prvi korak. Postopek ponovite še 7-krat saj sortiramo 8-bitna števila.
    for(int k=0; k<8; k++){
        extractBits(A, D, k);
        vector<int> indices(A.size());
        iota(indices.begin(), indices.end(), 0);

        //Bite (polje D) sortirajte s stabilnim algoritmom za sortiranje (najboljše counting sort).
        stable_sort(indices.begin(), indices.end(), [&](int i, int j){
            return D[i] < D[j];
        });

        rearrangeA(A, indices);
    }
}

void writeToFile(vector<unsigned char>& A){
    string outputFileName = "output.txt";
    ofstream outputFile(outputFileName);
    if(outputFile.is_open()){
        for(int i=0; i<A.size(); i++){
            outputFile << static_cast<int>(A[i]);
            if(i < A.size() - 1){
                outputFile << " ";
            }
        }
        outputFile.close();
        cout << "Urejena števila zapisana v: " << outputFileName << endl;
    }
    else{
        cerr << "Napaka pri odpiranju izhodne datoteke: " << outputFileName << endl;
    }
}

vector<unsigned char> readNumbersFromFile(std::string& filename){
    ifstream inputFile(filename);
    vector<unsigned char> A;

    if(!inputFile){
        cerr << "Napaka pri odpiranju datoteke" << endl;
        return A;
    }
    int number;
    while(inputFile >> number){
        if(number < 0 || number > 255){
            cerr << "Število izven ranga";
            return A;
        }
        A.push_back(static_cast<unsigned char>(number));
    }

    inputFile.close();
    return A;
}
