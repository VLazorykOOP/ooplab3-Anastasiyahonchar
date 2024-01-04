/*Створити тип даних - клас вектор, який має поля x, y та z типу float і змінну стану. У 
класі визначити 
o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля x, y та z
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити 
код помилки);
o деструктор із виведенням інформації про стан вектора;
o визначити функцію, яка присвоює полю x, y або z деяке значення (параметр за 
замовчуванням);
o функцію яка одержує деякий елемент з полів x, y та z;
o конструктор копій та операцію присвоєння; // !!!
o визначити функції друку, додавання, віднімання, векторний добуток які 
здійснюють ці арифметичні операції з даними цього класу;
o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не 
виконувати);
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.
У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в 
конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу. 
Написати програму тестування всіх можливостей цього класу.*/
#include <iostream>
#include <cmath>

using namespace std;

class Vector{
    float x, y, z;
    int state;

public : 
    static int count;
    Vector() : x(0), y(0), z(0){
        state = 0;
        count++;
    }

     Vector(float v) : x(v), y(v), z(v){
        state = 0;
        count++;
    }

    
    Vector(float* v1){
        if( v1 == nullptr ){
            state = 1; x = 0; y = 0; z = 0;
        }
        else{
            x = v1[0]; y = v1[1]; z = v1[2];
            state = 0;
        }
        count++;
    }

    ~Vector(){
    count--;
    cout << "Vector's state: " << state << endl;
    cout << "Vector delete" << endl;
    }

    void set(float v, char c){
        if (c == 'x') {
            x = v;
        } 
        else if (c == 'y') {
            y = v;
        } 
        else if (c == 'z') {
            z = v;
        } 
        else {
            cout << "Wrong component" << endl;
        }
    }

    float get(char c){
        if (c == 'x') {
            return x;
        } 
        else if (c == 'y') {
            return y;
        } 
        else if (c == 'z') {
            return z;
        } 
        else {
            cout << "Wrong component" << endl;
            return 0;
        }
    }

    Vector(const Vector& s){
        x = s.x;
        y = s.y;
        z = s.z;
        state = s.state;
        count++;
    }

    Vector& operator = (const Vector& s){
        if(this != &s){
        x = s.x;
        y = s.y;
        z = s.z;
        state = s.state;
        }
        return *this;
    }

    void print(){
        cout << "x: " << x << ", y: " << y << ", z: " << z << ", state: " << state << endl;
    }

    Vector operator + (const Vector& s){
    Vector tmp;
    tmp.x = x + s.x;
    tmp.y = y + s.y;
    tmp.z = z + s.z;
    return tmp;
    }

    Vector operator - (const Vector& s){
    Vector tmp;
    tmp.x = x - s.x;
    tmp.y = y - s.y;
    tmp.z = z - s.z;
    return tmp;
    }

    Vector operator * (const Vector& s){
    Vector tmp; 
    tmp.x = x * s.x;
    tmp.y = y * s.y;
    tmp.z = z * s.z;
    return tmp;
    }

    void Div(short div) {
        if (div != 0) {
            x /= div;
            y /= div;
            z /= div;
        } else state = 1; 
    }

    bool operator < (const Vector& s){
        if(x < s.x && y < s.y && z < s.z){
            return true;
        }
        else return false;
    }

    bool operator > (const Vector& s){
        if(x > s.x && y > s.y && z > s.z){
            return true;
        }
        else return false;
    }

    bool operator == (const Vector& s){
        if(x == s.x && y == s.y && z == s.z){
            return true;
        }
        else return false;
    }

};

int Vector::count = 0;

int main(){
    Vector v1;
    Vector v2(2);
    float v[3] = {1, 2, 3};
    Vector v3(v);
    cout << "Vector's count: " << Vector::count << endl;
    v1.print();
    v2.print();
    v3.print();

    Vector sum = v1 + v2;
    Vector dif = v2 - v3;
    Vector mult = v1 * v3;
    sum.print();
    dif.print();
    mult.print();

    v2.Div(3);
    v2.print();
    v2.Div(0);
    v2.print();

    if (v1 > v2) {
        cout << "v1 > v2" << endl;
    }
    if (v1 < v2) {
        cout << "v1 < v2" << endl;
    }
    if (v1 == v2) {
        cout << "v1 == v2" << endl;
    }

    return 0;
}