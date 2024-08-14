#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
#include <limits>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override
    {
        return b * b - 4 * a * c;
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override
    {
        auto discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return numeric_limits<double>::quiet_NaN();
        return discriminant;
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
        complex<double> disc{strategy.calculate_discriminant(a, b, c), 0};
        complex<double> root1 = (-b + sqrt(disc)) / (2 * a);
        complex<double> root2 = (-b - sqrt(disc)) / (2 * a);
        return {root1, root2};
    }
};