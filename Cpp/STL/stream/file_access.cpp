#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;


void writeCharsetToFile(const string& filename)
{
    ofstream file(filename.c_str());
    
    if (!file)
    {
        cerr << "can not open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 32; i < 256; ++i)
    {
        file << "value: " << setw(3) << i << " "
             << "char: " << static_cast<char>(i) << endl;
    }

    //会自动关闭文件
}

void outputFile(const string& filename)
{
    ifstream file(filename.c_str());

    if (!file)
    {
        cerr << "can not open file" << filename << endl;
        exit(EXIT_FAILURE);
    }

    char c;
    while (file.get(c))
    {
        cout.put(c);
    }

    //会自动关闭文件
}

int main()
{
    writeCharsetToFile("test.txt");
    outputFile("test.txt");
}