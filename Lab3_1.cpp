/*Створити клас типу – ромб ( поля : сторона, діагональ, колір). У класі визначити 
o конструктори ( не менше двох); 
o функції-члени обчислення площі, периметру;
o функції-члени встановлення значення сторони, діагоналі та кольору, функції 
встановлення полів класу повинні перевіряти коректність параметрів, що задаються; 
o функції-члени що повертають значення полів;
o функцію друку. 
Написати програму тестування всіх можливостей цього класу.*/
#include <iostream>
#include <cmath>

using namespace std;

class Romb{

    int side;
    float diagonal;
    int color;

public :
    Romb() : side(1), diagonal(1), color(0) {}
    Romb(int s, float d, int c) : side(s), diagonal(d), color(c) {}

    double S(){
        float diagonal2 = sqrt( side * side - 0.25 * ( diagonal * diagonal ));
        return 0.5 * ( diagonal * diagonal2 );
    }

    double P(){
        return 4 * side;
    }

    double getSide() const{
        return side;
    }

     double getDiagonal() const{
        return diagonal;
    }

     double getColor() const{
        return color;
    }

    void setSide(int s){ 
        if( s > 0 ){
            side = s;
        }
        else{
            cout << "Error" << endl;
        }
    }
    
    void setDiagonal(float d){ 
        if( d > 0 ){
            diagonal = d;
        }
        else{
            cout << "Error" << endl;
        }
    }

    void setColor(int c){ 
        if( c > 0 ){
            color = c;
        }
        else{
            cout << "Error"  << endl;
        }
    }

    void print(){
        cout<< "side: " << side << ", diagonal: " << diagonal << ", color: " << color << endl;
        cout<< "Square: " << S() << ", Perimeter: " << P() << endl;
    }

};

int main(){

    Romb obj;
    obj.print();
    int side;
    float diagonal; 
    int color;
    cout << "Input side: "; 
    cin >> side;
    cout << "Input digonal: "; 
    cin >> diagonal;
    cout << "Input color: "; 
    cin >> color;
    Romb obj1(side, diagonal, color);
    obj1.print();
    obj.setSide(-5);
    obj.print();
    obj.setSide(5);
    obj.print();
    obj.setDiagonal(-4);
    obj.print();
    obj.setDiagonal(4);
    obj.print();

    return 0;
}