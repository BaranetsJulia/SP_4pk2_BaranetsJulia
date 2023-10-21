// pz_12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MathLib.h"

int main()
{
    double a, b;
    std::cin >> a >> b;
    std::cout << "a + b = " << MathLibrary::Arithmetic::Add(a,b) << std::endl;
    std::cin >> a >> b;
    std::cout << "a - b = " << MathLibrary::Arithmetic::Subtract(a, b) << std::endl;
    std::cin >> a >> b;
    std::cout << "a * b = " << MathLibrary::Arithmetic::Multiply(a, b) << std::endl;
    std::cin >> a >> b;
    std::cout << "a / b = " << MathLibrary::Arithmetic::Divide(a, b) << std::endl;
    std::cin >> a >> b;
    std::cout << "a^b = " << MathLibrary::Arithmetic::Exponentiation(a, b) << std::endl;
    std::cin >> a >> b;
    std::cout << "a 1.0/b = " << MathLibrary::Arithmetic::Root(a, b) << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
