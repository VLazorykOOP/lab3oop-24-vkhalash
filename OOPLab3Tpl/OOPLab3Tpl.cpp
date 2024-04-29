#include <iostream>

using namespace std;

void MenuTask()
{
    cout << "    Menu Task\n";
    cout << "    1.  Task 1\n";
    cout << "    2.  Task 2\n";
    cout << "    3.  Exit\n";
}

/*
Створити клас типу – паралелограм (поля : основа, висота, бічна сторона, колір).
У класі визначити:
- конструктори (не менше двох);
- функції-члени обчислення площі, периметру;
- функції-члени встановлення основи, висоти, бічної сторони, кольору,
функції встановлення полів класу повинні перевіряти коректність параметрів, що задаються;
- функції-члени що повертають значення полів;
- функцію друку. Написати програму тестування всіх можливостей цього класу.
*/
class Parallelogram
{
private:
    double base;
    double height;
    double side;
    double color;

public:
    // Constructors
    Parallelogram() : base(1), height(1), side(1), color(1) {}
    Parallelogram(double b) : base(b), height(1), side(1), color(1) {}
    Parallelogram(double b, double h) : base(b), height(h), side(1), color(1) {}
    Parallelogram(double b, double h, double s) : base(b), height(h), side(s), color(1) {}
    Parallelogram(double b, double h, double s, double c) : base(b), height(h), side(s), color(c) {}

    // Member functions for calculating area, perimeter
    double calculateArea() { return base * height; }
    double calculatePerimeter() { return 2 * (base + side); }

    // Member functions for setting class fields
    void setBase(double b) { base = b; }
    double getBase() const { return base; }

    void setHeight(double h) { height = h; }
    double getHeight() const { return height; }

    void setSide(double s) { side = s; }
    double getSide() const { return side; }

    void setColor(double c) { color = c; }
    double getColor() const { return color; }

    // Print function
    void Output()
    {
        cout << "Base " << base << endl;
        cout << "Height " << height << endl;
        cout << "Side " << side << endl;
        cout << "Color " << color << endl;
        cout << "Area " << calculateArea() << endl;
        cout << "Perimeter " << calculatePerimeter() << endl;
        cout << endl;
    }

    // Console input function
    static Parallelogram ConsoleInput()
    {
        double inBase, inHeight, inSide, inColor;
        cout << "Input base value: ";
        cin >> inBase;
        cout << "Input height value: ";
        cin >> inHeight;
        cout << "Input side value: ";
        cin >> inSide;
        cout << "Input color value: ";
        cin >> inColor;
        cout << endl;

        if (inBase <= 0 || inHeight <= 0 || inSide <= 0 || inColor < 0)
        {
            throw invalid_argument("Invalid input");
        }
        else
        {
            Parallelogram p, p1(inBase), p2(inBase, inHeight),
                p3(inBase, inHeight, inSide), p4(inBase, inHeight, inSide, inColor);
            cout << "Default\n";
            p.Output();
            cout << "Paralellogram 1\n";
            p1.Output();
            cout << "Paralellogram 2\n";
            p2.Output();
            cout << "Paralellogram 3\n";
            p3.Output();
            cout << "Paralellogram 4\n";
            p4.Output();
        }
        return Parallelogram();
    }
};

/*Створити тип даних - клас вектор, який має вказівник на short, число елементів і змінну стану.
У класі визначити:
- конструктор без параметрів (виділяє місце для одного елемента та інінціалізує його в нуль);
- конструктор з одним параметром - розмір вектора (виділяє місце та інінціалізує масив значенням нуль);
- конструктор із двома параметрами - розмір вектора та значення ініціалізації
(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу);
- конструктор копій та операцію присвоєння;
- деструктор звільняє пам'ять;
- визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
- функцію яка одержує деякий елемент масиву;
- визначити функції друку, додавання, віднімання, які здійснюють ці арифметичні операції з даними
цього класу, множення на ціле типу unsigned char;
- визначити функції порівняння: більше, нерівно або рівно, які повертають true або false.
*/
class Vector
{
    short *v;
    int num;
    int state;

public:
    // Constructors
    Vector() : v(NULL), num(0), state(0) {}
    Vector(int n);
    Vector(int n, short &);
    Vector(int n, short *);
    Vector(const Vector &s);

    // Assignment operator
    Vector &operator=(const Vector &s);

    // Destructor
    ~Vector()
    {
        if (v)
            delete[] v;
    }

    // Define functions
    void Output();
    Vector Add(Vector &b);
    Vector Subtract(Vector &b);
    Vector Multiply(Vector &b);
    Vector Greater(Vector &b);
    Vector Smaller(Vector &b);
    Vector Equal(Vector &b);
    static Vector ConsoleInput();
};

// Constructor with one parameter
Vector::Vector(int n)
{
    if (n <= 0)
    {
        v = NULL;
        num = 0;
        state = -1;
        cout << " Vec --> 0 ";
    }
    num = n;
    v = new short[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
}

// Constructor with two parameters
Vector::Vector(int n, short &b)
{
    if (n <= 0)
    {
        v = NULL;
        num = 0;
        state = -1;
        cout << " Vec --> 0 ";
    }
    num = n;
    v = new short[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = b;
    }
}

// Copy constructor
Vector::Vector(const Vector &s)
{
    num = s.num;
    v = new short[num];
    state = 0;
    for (int i = 0; i < num; i++)
        v[i] = s.v[i];
}

// Assignment operator
Vector &Vector::operator=(const Vector &s)
{
    if (num != s.num)
    {
        if (v)
            delete[] v;
        num = s.num;
        v = new short[num];
        state = 0;
    }
    for (int i = 0; i < num; i++)
        v[i] = s.v[i];
    return *this;
}

// Print function
void Vector::Output()
{
    if (num != 0)
    {
        for (int i = 0; i < num; i++)
        {
            cout << " v [ " << i << " ] " << v[i] << '\t';
            cout << endl;
        }
    }
}

// Action functions
Vector Vector::Add(Vector &b)
{
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0)
    {
        Vector tmp(tnum);
        for (int i = 0; i < tnum; i++)
            tmp.v[i] = v[i] + b.v[i];
        return tmp;
    }
    return Vector(0);
}

Vector Vector::Subtract(Vector &b)
{
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0)
    {
        Vector tmp(tnum);
        for (int i = 0; i < tnum; i++)
            tmp.v[i] = v[i] - b.v[i];
        return tmp;
    }
    return Vector(0);
}

Vector Vector::Multiply(Vector &b)
{
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0)
    {
        Vector tmp(tnum);
        for (int i = 0; i < tnum; i++)
            tmp.v[i] = v[i] * b.v[i];
        return tmp;
    }
    return Vector(0);
}

Vector Vector::Greater(Vector &b)
{
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0)
    {
        Vector tmp(tnum);
        for (int i = 0; i < tnum; i++)
        {
            if (v[i] > b.v[i])
                cout << "true\n";
            if (v[i] <= b.v[i])
                cout << "false\n";
        }
        return tmp;
    }
    return Vector(0);
}

Vector Vector::Smaller(Vector &b)
{
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0)
    {
        Vector tmp(tnum);
        for (int i = 0; i < tnum; i++)
        {
            if (v[i] < b.v[i])
                cout << "true\n";
            if (v[i] >= b.v[i])
                cout << "false\n";
        }
        return tmp;
    }
    return Vector(0);
}

Vector Vector::Equal(Vector &b)
{
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0)
    {
        Vector tmp(tnum);
        bool equal = true;
        for (int i = 0; i < tnum; i++)
        {
            if (v[i] != b.v[i])
            {
                equal = false;
                break;
            }
        }
        if (equal)
            cout << "true\n";
        else
            cout << "false\n";
        return tmp;
    }
    return Vector(0);
}

// Console input function
Vector Vector::ConsoleInput()
{
    Vector vec;
    cout << "Vector 1\n";
    cout << "Size ";
    int n;
    cin >> n;
    Vector v(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << " ";
        cin >> v.v[i];
    }

    cout << "Vector 2\n";
    cout << "Size ";
    Vector b(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << " ";
        cin >> b.v[i];
    }

    cout << "\nSubtract\n";
    v.Subtract(b).Output();

    cout << "\nMultiply\n";
    v.Multiply(b).Output();

    cout << "\nAdd\n";
    v.Add(b).Output();

    cout << "\nGreater\n";
    v.Greater(b);

    cout << "\nSmaller\n";
    v.Smaller(b);

    cout << "\nEqual\n";
    v.Equal(b);

    return vec;
}

int main()
{
    MenuTask();

    int choice;

    do
    {
        cout << "Choice ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Test program for task 1
        {
            try
            {
                Parallelogram p = Parallelogram::ConsoleInput();
            }
            catch (const invalid_argument &e)
            {
                cout << "Error " << e.what() << endl;
            }
            choice = 3;
            break;
        }
        case 2: // Test program for task 2
        {
            Vector v = Vector::ConsoleInput();
            choice = 3;
            break;
        }
        case 3: // Exit
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
