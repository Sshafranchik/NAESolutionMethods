#include "NAEsol_met.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip> 

using namespace std;
using namespace std::chrono;


int main() {
    setlocale(LC_ALL, "ukr");
    double a, b, step, epsilon; int maxiterations = 1000;
    cout << "Введіть початкове значення інтервалу a: ";
    cin >> a;
    cout << "Введіть кінцеве значення інтервалу b: ";
    cin >> b;
    cout << "Введіть крок для методу перебору: ";
    cin >> step;
    cout << "Введіть точність epsilon: ";
    cin >> epsilon;

    auto start = steady_clock::now();
    double root1 = PickingMethod(a, b, step, epsilon);
    auto end = steady_clock::now();
    auto time1 = duration_cast<duration<double>>(end - start);

    start = steady_clock::now();
    double root2 = BisectionMethod(a, b, epsilon);
    end = steady_clock::now();
    auto time2 = duration_cast<duration<double>>(end - start);

    start = steady_clock::now();
    double root3 = SecantMethod(a, b, epsilon);
    end = steady_clock::now();
    auto time3 = duration_cast<duration<double>>(end - start);

    start = steady_clock::now();
    double root4 = NewtonMethod((a + b) / 2, epsilon);
    end = steady_clock::now();
    auto time4 = duration_cast<duration<double>>(end - start);

    start = steady_clock::now();
    double root5 = Secant_NewtonMethod(a, b, epsilon);
    end = steady_clock::now();
    auto time5 = duration_cast<duration<double>>(end - start);

    start = steady_clock::now();
    double root6 = IterationsMethod((a + b) / 2, epsilon,maxiterations);
    end = steady_clock::now();
    auto time6 = duration_cast<duration<double>>(end - start);

    cout << fixed << setprecision(10);//std::fixed встановлює фіксований формат для чисел з плаваючою точкою. //
    cout << "Метод перебору: корінь = " << root1 << ", час = " << time1.count() << " секунд" << endl;
    cout << "Метод половинного ділення: корінь = " << root2 << ", час = " << time2.count() << " секунд" << endl;
    cout << "Метод хорд: корінь = " << root3 << ", час = " << time3.count() << " секунд" << endl;
    cout << "Метод дотичних (метод Ньютона): корінь = " << root4 << ", час = " << time4.count() << " секунд" << endl;
    cout << "Метод хорд-дотичних: корінь = " << root5 << ", час = " << time5.count() << " секунд" << endl;
    cout << "Метод ітерацій: корінь = " << root6 << ", час = " << time6.count() << " секунд" << endl;

    double minTime = time1.count();
    minTime = min(minTime, time2.count());
    minTime = min(minTime, time3.count());
    minTime = min(minTime, time4.count());
    minTime = min(minTime, time5.count());
    minTime = min(minTime, time6.count());
    cout << endl;
    cout << "Найменший час виконання: " << minTime << " секунд" << endl;

    return 0;
