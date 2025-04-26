#include <iostream>
using namespace std;

// Базовый класс - точка на плоскости
class Point2D {
protected:
    double x, y;  // Координаты точки
public:
    // Конструктор для инициализации координат
    Point2D(double x, double y) : x(x), y(y) {}
    
    // Виртуальный метод для печати координат
    virtual void print() const {
        cout << "2D точка: (" << x << ", " << y << ")";
    }
    
    virtual ~Point2D() {}  // Виртуальный деструктор
};

// Производный класс - точка в трехмерном пространстве
class Point3D : public Point2D {
    double z;  // Дополнительная координата z
public:
    // Конструктор с вызовом конструктора базового класса
    Point3D(double x, double y, double z) : Point2D(x, y), z(z) {}
    
    // Переопределенный метод печати
    void print() const override {
        Point2D::print();  // Вызов метода базового класса
        cout << ", " << z << ")";  // Добавление z-координаты
    }
};

int main() {
    // Создание объектов
    Point2D p2d(1.5, 2.5);
    Point3D p3d(3.0, 4.0, 5.0);
    
    // Прямой вызов методов
    cout << "Прямой вызов методов:\n";
    p2d.print(); cout << endl;
    p3d.print(); cout << endl << endl;
    
    // Демонстрация динамического полиморфизма
    cout << "Демонстрация полиморфизма:\n";
    Point2D* ptr = &p2d;
    ptr->print(); cout << endl;  // Вызов Point2D::print()
    
    ptr = &p3d;
    ptr->print(); cout << endl;  // Вызов Point3D::print() благодаря virtual
    
    return 0;
}
