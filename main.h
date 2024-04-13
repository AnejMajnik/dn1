#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <string>

void rearrangeA(std::vector<unsigned char>& A, const std::vector<int>& indices);
void printArr(const std::vector<unsigned char>& arr);
void extractBits(const std::vector<unsigned char>& A, std::vector<unsigned char>& D, int k);
void binaryRadixSort(std::vector<unsigned char>& A);
void writeToFile(std::vector<unsigned char>& A);
std::vector<unsigned char> readNumbersFromFile(const std::string& filename);

#endif // MAIN_H
