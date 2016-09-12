#include <iostream>
#include <ctime>
#include <windows.h>
#include <stdio.h>
//#include <iomanip>
//#include <stdafx>

#define row 5 //количество строк
#define col 5 //количество столбцов
using namespace std;

void MatrDel(byte** arr); // процедура освобождения памяти, выделенной под матрицу
void arrPrint(byte** arr); // процедура вывода массива
void arrIn(byte** arr); // процедура заполнения массива случайными числами
void matrInArrRightDiag(byte** matr, byte* arr2); // процедура записи матрицы в одномерный массив по правым диагоналям
void arrDel(byte* arr); // процедура освобождения памяти, выделенной под одномерный массив

int main(int argc, char** argv) {
	int i;
	srand(time(0)); // генерация случайных чисел
	byte **arr = new byte*[row]; // динамическое создание двумерного массива типа byte размерностью row
	for (i = 0; i < row; i++)
        arr[i] = new byte [col]; // количество столбцов - col
    
    arrIn(arr); // заполним рандомно массив
    arrPrint(arr); // вывод массива в консоль
    
    byte *arr2 = new byte[row * col]; // создадим одномерный массив размером row*col и выделим под него память
    matrInArrRightDiag(arr, arr2); // перепишем матрицу в одномерный массив по правым диагоналям
    
    //MatrDel(arr); // освободим память, выделенную под матрицу
    //arrDel(arr2); // освободим память, выделенную под одномерный массив
	system("pause");
	return 0;
}

// процедура освобождения памяти, выделенной под матрицу
void MatrDel(byte** arr){
	// удаление матрицы
    for (int i = 0; i < row; i++){
    	delete []arr[i];
    }
    printf("Matrix was deleted!\n");	
}

// процедура освобождения памяти, выделенной под одномерный массив
void arrDel(byte* arr){
	// удаление массива
    delete []arr;
    printf("Array was deleted!\n");	
}

// процедура вывода массива
void arrPrint(byte** arr){
    // вывод массива
    for (int i = 0; i < row; i++){
    	for (int j = 0; j < row; j++){
    	//	printf("arr[%d][%d] = %d ", i, j, (int)arr[i][j]);
    		printf("%d ",(int)arr[i][j]);
    	}
    	printf("\n");
    }
    printf("\n");
}

// процедура заполнения массива случайными числами
void arrIn(byte** arr){ // rows - количество строк, cols - количество столбцов
	// заполнение массива случайными числами   
    for (int i = 0; i < row; i++){
    	for (int j = 0; j < col; j++){
    		arr[i][j] = (rand() % 10 + 1) / byte((rand() % 10 + 1)); //заполнение массива случайными числами с масштабированием от 1 до 10
    	}
    }
    printf("Array was filled!\n\n"); 
}

// процедура записи матрицы в одномерный массив по правым диагоналям
void matrInArrRightDiag(byte** matr, byte* arr2){ // matr - матрица, arr2 - одномерный массив (вектор)
	int count = 0; // счетчик для одномерного массива
	int lim_i = 0;
    int lim_j = row - 1;
    int i, j, k, l;
    
    // заполнение с правого угла до главной диагонали включительно
	for (i = 0, j = row - 1; (i <= lim_i) && (j <= lim_j) && (lim_i != col); lim_i++, j--) {
 		for (k = i, l = j; (k <= lim_i) && (l <= lim_j); k++, l++) {
 			arr2[count] = matr[k][l];
			cout << (int)arr2[count];
			count++;
 		}
    }
    
	// заполнение после главное диагонали 
    int p = 1;
 	for(k = 0; k < col - 1; k++){
 		for(i = p, j = 0; (i < col) && (j < lim_j); i++, j++){
 			arr2[count] = matr[i][j];
 			cout << (int)arr2[count];
 			count++;
 			
 		}
 		lim_j--;
 		p++;
 	}
    
    printf("\n\nMatrix was rewrite in other array!\n"); 
}
