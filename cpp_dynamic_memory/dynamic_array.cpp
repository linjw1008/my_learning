//动态数组

#include <iostream>
using namespace std;

int main()
{
    //一维数组
    char* pchar = NULL;
    pchar = new char[20];
    for(int i = 0; i < 19; i++)
    {
        pchar[i] = 'a';
    }
    pchar[19] = '\0';
    cout << "The value of *pchar is: " << *pchar << endl;
    cout << "The address of pointer pchar is: " << pchar << endl;
    delete [] pchar;


    //二维数组
    int **array = NULL;
    array = new int*[20];
    cout << "The pointer array is: " << array << endl;
    for(int i = 0; i < 20; i++)
    {
        array[i] = new int[20];
        cout << "The pointer array[" << i << "] is: " << array[i] << endl; 
    }
    for(int j = 0; j < 20; j++)
    {
        for(int k = 0; k < 20; k++)
        {
            array[j][k] = j*k;
        }
    }
    for(int j = 0; j < 20; j++)
    {
        for(int k = 0; k < 20; k++)
        {
            cout << array[j][k] << '\t';
        }
        cout << endl;
    }
    //释放内存
    for(int j = 0; j < 20; j++)
    {
        delete [] array[j];
    }
    delete [] array;


	//三维数组
	int ***array_3 = NULL;
    array_3 = new int** [5];
    cout << "The pointer array is: " << array_3 << endl;
    for(int i = 0; i < 5; i++)
    {
        array_3[i] = new int* [5];
        cout << "The pointer array[" << i << "] is: " << array_3[i] << endl;
        for(int j = 0; j < 5; j++)
        {
            array_3[i][j] = new int [5];
            cout << "The pointer array[" << i << "][" << j << "] is: " << array_3[i][j] << endl;
        }
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                array_3[i][j][k] = i*j*k;
                cout << array_3[i][j][k] << '\t';
            }
        }
        cout << endl;
    }
    for(int j = 0; j < 5; j++)
    {
        for(int k = 0; k < 5; k++)
        {
            delete [] array_3[j][k];
        }
    }
    for(int i = 0; i < 5; i++)
    {
        delete [] array_3[i];
    }
    delete [] array_3;
    system("pause");

    return 0;

}