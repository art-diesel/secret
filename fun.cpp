#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <cstring>

using std::cout;
using std::cin;
using std::string;

struct Employee{
    string surname{};
    size_t children{};
}*employees;


void CheckFile(std::ifstream& file){
    if(!file){
        throw std::logic_error("Файла не существует!");
    }
    file.seekg(0,std::ios::end);
    if(file.tellg() == 0){
        throw std::logic_error("Файл пуст!");
    }
    file.seekg(0,std::ios::beg);
    
}
void InputDelim(std::ifstream& file,string& delim){
    getline(file,delim);
    cout << delim << '\n';
}
int32_t Counter(std::ifstream& file) {
    file.clear();
    file.seekg(0);
    std::string delim, str, words;
    getline(file, delim);
    int32_t c = 0;
    while (getline(file, str)) {
        for (char& ch : str){
            if (delim.find(ch) != -1){
                 ch = ' ';
            }
        }
        std::istringstream ss(str);
        while (ss >> words) {
            int i = 0;
            if (words[0] == '-'){
                i = 1;
            }
            if (i == words.size()){
                continue;
            }
            while (i < words.size() && isdigit(words[i])){
                 ++i;
            }
            if (i == words.size()){
                ++c;
            }
        }
    }
    std::cout << "count = " << c << '\n';
    return c;
}



void AllocArray(int32_t*& array,std::ifstream& file,int32_t size){
    array = new int32_t[size];
}



void FillArray(std::ifstream& file, int32_t* array) {
    file.clear();
    file.seekg(0);
    std::string delim, str, words;
    getline(file, delim);
    int32_t i = 0;
    while (getline(file, str)) {
        for (char& ch : str){
            if (delim.find(ch) != -1){
                ch = ' ';
            }
        }
        std::istringstream ss(str);
        while (ss >> words) {
            int j = 0;
            if (words[0] == '-'){
                j = 1;
            }
            if (j == words.size()){
                continue;
            }
            while (j < words.size() && words[j] >= '0' && words[j] <= '9'){
                ++j;
            }
            if (j == words.size()){
                array[i++] = std::stoi(words);
            }
        }
    }
}

void OutputArray(int32_t* array,std::ifstream& file,int32_t size){
    
    for(int32_t i = 0;i < size;++i){
        cout << array[i] << " ";
    }
}
void AllocAllNumbers(int32_t*& allNumbers,int32_t size){
    allNumbers = new int32_t[size];
}
bool isEven(int32_t number){
    return !(number & 1);
}
void InputSortArray(int32_t* array,int32_t* allNumbers,int32_t size){
    int32_t j = 0;
    for(int32_t i = 0;i < size;++i){
        if(isEven(array[i]) == true){
            allNumbers[j++] = array[i];
        }
    }
    for(int32_t i = 0;i < size;++i){
        if(isEven(array[i]) == false){
            allNumbers[j++] = array[i];
        }
    }
}

void OutputAllNumbers(int32_t* allNumbers,int32_t size){
    for(int32_t i = 0;i < size;++i){
        cout << allNumbers[i] << " ";
    }
    cout << '\n';
}
int32_t Digit(int32_t a){
    int32_t counter{};
    if(a == 0){
        return 1;
    }
    while(a  >= 0){
        a /= 10;
        counter++;
    }
    return counter;
}
void inputSortAllNumbers(int32_t* array,int32_t* allNumbers,int32_t size){

}

template<typename T, typename Compare>
int partition(T* arr, int low, int high, Compare comp) {
    T pivot = arr[high];
    int counter = low;

    for (int i = low; i < high; i++) {
        if (comp(arr[i],pivot)) {
            std::swap(arr[i], arr[counter++]);
        }
    }
    std::swap(arr[high], arr[counter]);

    return counter;
}

template<typename T, typename Compare>
void myQuickSort(T* arr, int low, int high, Compare comp) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comp);
        myQuickSort(arr, low, pivotIndex - 1, comp);
        myQuickSort(arr, pivotIndex + 1, high, comp);
    }
}

bool compare(int a,int b){
    return a < b;
}


int32_t CounterSurnames(std::ifstream& fileSurnames){
    fileSurnames.clear();
    fileSurnames.seekg(0,std::ios::beg);
    string delimSurnames{};
    getline(fileSurnames,delimSurnames);
    int32_t counter{};
    string temp{},words{};
    char ch{};
    while(fileSurnames >> temp){
        for (char& ch : temp){
            if (delimSurnames.find(ch) != -1){
                ch = ' ';
            }
        }
        std::istringstream ss(temp);
        while (ss >> words) {
            int32_t j = 0;
            while (j < words.size() && isalpha(words[j])){
                ++j;
            }
            if (j == words.size()){
                ++counter;
            }
        }
    }
    if(counter <= 0){
        throw std::logic_error("Неверный размер массива!");
    }
    return counter;

}
void AllocSurnames(string*& allSurnames,int32_t sizeSurnames){
    allSurnames = new string[sizeSurnames];
}
void FillAllSurnames(std::ifstream& fileSurnames, int32_t sizeSurnames, std::string* allSurnames) {
    fileSurnames.clear();
    fileSurnames.seekg(0);
    std::string delim, line, word;
    getline(fileSurnames, delim);
    int32_t i = 0;

    while (getline(fileSurnames, line)) {
        for (char& c : line)
            if (delim.find(c) != -1) c = ' ';
        std::istringstream ss(line);
        while (ss >> word) {
            int j = 0;
            while (j < word.size() && std::isalpha(word[j])) ++j;
            if (j == word.size() && i < sizeSurnames)
                allSurnames[i++] = word;
        }
    }
}


#include <cctype> // для std::tolower

int CompareSurnames(const void* a, const void* b) {
    const std::string* s1 = static_cast<const std::string*>(a);
    const std::string* s2 = static_cast<const std::string*>(b);

    const size_t len = std::min(s1->size(), s2->size());
    for (size_t i = 0; i < len; ++i) {
        unsigned char c1 = (*s1)[i];
        unsigned char c2 = (*s2)[i];
        if (c1 != c2) return c1 - c2;
    }

    // Если все символы совпали — сравниваем по длине
    return (int)(s1->size() - s2->size());
}





void PrintSurnames(string* allSurnames, int32_t sizeSurnames){
    cout << "\nОтсортированные фамилии:\n";
    for (int32_t i = 0; i < sizeSurnames; ++i) {
        cout << allSurnames[i] << '\n';
    }
}
void AllocEmployees(Employee* employees,int32_t sizeSurnames){
    employees = new Employee[sizeSurnames];
}
