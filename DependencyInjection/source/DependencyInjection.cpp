#include <iostream>
#include "DiscreteFunction.h"
#include <vector>
#include <memory>

int main()
{
    std::vector<double> ys(21);
    double delta_x = 1.0 / 20;
    for(size_t i = 0; i < ys.size(); i++)
    {
        double x = delta_x * i;
        ys[i] = x*x;
    }
    std::unique_ptr<Integrator> integratorPtr = std::make_unique<TrapeziumIntegrator>();
    // DiscreteFunction DF(ys, 0, 1, integratorPtr);
    DiscreteFunction DF(ys, 0, 1);
    // DF.setIntegrator(integratorPtr);

    std::cout << DF.integrate() << std::endl;

    return 0;
}