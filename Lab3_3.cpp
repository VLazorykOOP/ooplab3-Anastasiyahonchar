/*Створити клас матриця. Даний клас містить вказівник на вказівник на double, розміри 
рядків і стовпців та стан помилки. У класі визначити 
o конструктор без параметрів( виділяє місце для матриці 2 на 2 елемента та 
інінціалізує його в нуль);
o конструктор з одним параметром – розмір n матриці (виділяє місце n на n та 
інінціалізує матрицю значенням нуль);
o конструктор із трьома параметрами розміри матриці (n , m) та значення 
ініціалізації value (виділяє місце перші аргументи та інінціалізує значенням 
третього аргументу - value);
o конструктор копій та операцію присвоєння; // !!!
o деструктор звільняє пам'ять;
o визначити функцію, яка присвоює елементу масиву деяке значення (параметр за 
замовчуванням);
o функцію яка одержує деякий елемент матриці за індексами i та j;
o визначити функції друку, додавання, множення, віднімання, які здійснюють ці 
арифметичні операції з даними цього класу;
o визначити функцію ділення матриці на скаляр типу int (у випадку якщо скаляр 
рівний нулю ділення не виконувати);
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі 
матриці, ділення на 0. Передбачити можливість підрахунку числа об'єктів даного типу. 
Написати програму тестування всіх можливостей цього класу*/

#include <iostream>
#include <cmath>

using namespace std;

class Matrix{
    int rows, columns, state;
    double **p;

public :
    Matrix() : rows(2), columns(2){
        p = new double*[rows];
        for (int i = 0; i < rows; i++){
            p[i] = new double[columns];
            for (int j = 0; j < columns; j++){
                p[i][j] = 0;
                state = 0;
            }
        }
    }

    Matrix(int n) : rows(n), columns(n){
        p = new double*[rows];
        for (int i = 0; i < rows; i++){
            p[i] = new double[columns];
            for (int j = 0; j < columns; j++){
                p[i][j] = 0;
                state = 0;
            }
        }
    }

    Matrix(int n, int m, double value) : rows(n), columns(m){
        p = new double*[rows];
        for (int i = 0; i < rows; i++){
            p[i] = new double[columns];
            for (int j = 0; j < columns; j++){
                p[i][j] = value;
            }
        }
    }

    Matrix(const Matrix& s){
    rows = s.rows;
    columns = s.columns;
    state = s.state; 
    p = new double*[rows];
        for (int i = 0; i < rows; i++){
            p[i] = new double[columns];
            for (int j = 0; j < columns; j++){
                p[i][j] = s.p[i][j];
            }
        }
    }

    Matrix& operator = (const Matrix& s){
        if (this != &s){
        rows = s.rows;
        columns = s.columns;
        state = s.state;
        p = new double*[rows];
        for (int i = 0; i < rows; i++){
            p[i] = new double[columns];
            for (int j = 0; j < columns; j++){
                p[i][j] = s.p[i][j];
            }
        }
        }
        return *this;
    }

    ~Matrix(){
        for (int i = 0; i < rows; i++){
            delete[] p[i];
        }
        delete[] p;
    }

    void set(int i, int j, double value = 0){
        if (i >= 0 && i < rows && j >= 0 && j < columns){
            p[i][j] = value;
        } 
        else state = 1;
    }

    double get(int i, int j){
        if (i >= 0 && i < rows && j >= 0 && j < columns){
            return p[i][j];
        } 
        else {
            state = 1; 
            return 0;
        }
    }

    void print(){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator + (const Matrix& s){
    Matrix tmp(rows, columns, 0);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                tmp.p[i][j] = p[i][j] + s.p[i][j];
            }
        }
            return tmp;
       
    }

    Matrix operator - (const Matrix& s){
    Matrix tmp(rows, columns, 0);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                tmp.p[i][j] = p[i][j] - s.p[i][j];
            }
        }
            return tmp;
       
    }

    Matrix operator * (const Matrix& s){
    Matrix tmp(rows, columns, 0);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                tmp.p[i][j] = p[i][j] * s.p[i][j];
            }
        }
            return tmp;
       
    }

    void Div(int div){
        if (div != 0){
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < columns; j++){
                    p[i][j] /= div;
                }
            }
        } 
        else state = 1;
    }

    bool operator > (const Matrix& s){
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < columns; j++){
                    if (p[i][j] > s.p[i][j]){
                        return true;
                    }
                    else return false;
                }
            }
    } 

    bool operator < (const Matrix& s){
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < columns; j++){
                    if (p[i][j] < s.p[i][j]){
                        return true;
                    }
                    else return false;
                }
            }
    } 

    bool operator == (const Matrix& s){
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < columns; j++){
                    if (p[i][j] == s.p[i][j]){
                        return true;
                    }
                    else return false;
                }
            }
    } 
    

};

int main() {
    
    Matrix mat1; 
    Matrix mat2(2); 
    Matrix mat3(2, 2, 5); 
    Matrix mat4 = mat3;
    mat1.set(0, 0, 2.5);
    double v = mat1.get(0, 0);
    mat1.set(1, 1, 3.25);
    double v1 = mat1.get(1, 1);
    mat1.print();
    mat2.print();
    mat3.print();
    mat4.print();

    Matrix sum = mat1 + mat3;
    Matrix dif = mat1 - mat2;
    Matrix mult = mat1 * mat3;
    sum.print();
    dif.print();
    mult.print();
    mat3.Div(2);
    mat3.print();

    if (mat1 > mat2) {
        cout << "mat1 > mat2" << endl;
    }
    if (mat1 < mat2) {
        cout << "mat1 < mat2" << endl;
    }
    if (mat1 == mat2) {
        cout << "mat1 = mat2" << endl;
    }

    return 0;
}