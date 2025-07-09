#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "header.h"
#include <new>

using std::cout;
using std::cin;
using std::string;



int main(){
    std::ifstream file("numbrs.txt");
    std::ifstream fileSurnames("surnames.txt");
    string delim{};
    string temp{};
    int32_t* array{};
    int32_t* allNumbers{};
    string* allSurnames{};
    int32_t sizeSurnames{};
    int32_t size{};
    try{
        CheckFile(file);
        InputDelim(file,delim);
        size = Counter(file);
        AllocArray(array,file,size);
        FillArray(file,array);
        OutputArray(array,file,size);
        AllocAllNumbers(allNumbers,size);
        InputSortArray(array,allNumbers,size);
        cout << '\n';
        OutputAllNumbers(allNumbers,size);
        int32_t sizeSurnames = CounterSurnames(fileSurnames);
        AllocSurnames(allSurnames,sizeSurnames);
        FillAllSurnames(fileSurnames,sizeSurnames,allSurnames);
        qsort(allSurnames,sizeSurnames,sizeof(string),CompareSurnames);
        PrintSurnames(allSurnames,sizeSurnames);
    }
    catch(const std::logic_error& e){
        cout << '\n' << e.what() << '\n';
    }
    catch(const std::bad_alloc& e){
        cout << "Ошибка сегментации!" << '\n';
    }
    return 0;
}

