#pragma once
double nonlinearFunction(double x);
double derivativeFunction(double x);
double PickingMethod(double a, double b, double step, double epsilon);
double BisectionMethod(double a, double b, double epsilon);
double SecantMethod(double a, double b, double epsilon);
double NewtonMethod(double x0, double epsilon);
double Secant_NewtonMethod(double a, double b, double epsilon);
double IterationsMethod(double x0, double epsilon, int maxiterations);
