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
    std::unique_ptr<Integrator> trapeziumIntegrator = std::make_unique<TrapeziumIntegrator>();

    // DiscreteFunction DF(ys, 0, 1, std::make_unique<TrapeziumIntegrator>()); 
    // NOT WORKING BECAUSE if you put it in the parameter, it doesn't have an address yet (temporary)
    // so you should assign it first to the Left hand side (have an address), then it will pass by reference in the parameter

    // DiscreteFunction DF(ys, 0, 1, integratorPtr);
    DiscreteFunction DF(ys, 0, 1);
    DF.setIntegrator(trapeziumIntegrator);

    std::cout << "TrapeziumIntegrator: " << DF.integrate() << std::endl;

    std::unique_ptr<Integrator> simpsonIntegrator = std::make_unique<SimpsonIntegrator>();
    DF.setIntegrator(simpsonIntegrator);
    std::cout << "SimpsonIntegrator: " << DF.integrate() << std::endl;

    return 0;
}