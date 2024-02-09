#include "DiscreteFunction.h"
#include <stdexcept>

DiscreteFunction::DiscreteFunction(std::vector<double> y, double x_min, double x_max, std::unique_ptr<Integrator> &integratorPtr) : max_x(x_max), min_x(x_min)
{
    initializeValue(y);

    // integrator = std::make_unique<TrapeziumIntegrator>();
    // https://github-pages.ucl.ac.uk/research-computing-with-cpp/05libraries/sec01DesigningClasses.html
    
    // this->integrator = std::move(integratorPtr);
    setIntegrator(integratorPtr);
}

DiscreteFunction::DiscreteFunction(std::vector<double> y, double x_min, double x_max) : max_x(x_max), min_x(x_min) {
    initializeValue(y);
}

void DiscreteFunction::setIntegrator(std::unique_ptr<Integrator> &integratorPtr) {
    this->integrator = std::move(integratorPtr);
}

void DiscreteFunction::initializeValue(std::vector<double> y) {
    if(y.size() < 3)
    {
        throw std::runtime_error("Discrete function must be represented at at least 3 points.");
    }
    if(y.size() % 2 != 1)
    {
        throw std::runtime_error("Discrete function must be represented at an odd number of points.");
    }
    // If y is a valid function representation then move data ownership to this object
    // y (passing in vector) will be left empty
    ys = std::move(y);

    delta_x = (this->max_x - this->min_x) / (ys.size()-1);
}

double DiscreteFunction::integrate()
{
    if (integrator) {
        return integrator->integrate(delta_x, ys);
    } else {
        throw std::invalid_argument("Integrator pointer is empty!");
    }
}

SimpsonIntegrator::SimpsonIntegrator() {};

TrapeziumIntegrator::TrapeziumIntegrator() {};

double SimpsonIntegrator::integrate(const double delta_x, const std::vector<double> &ys)
{
    double total = ys[0];
    for(size_t i = 1; i < ys.size()-1; i++)
    {
        total += (i%2==1 ? 4 : 2) * ys[i];
    }
    total += ys[ys.size()-1];
    total *= delta_x / 3;
    return total;
}

double TrapeziumIntegrator::integrate(const double delta_x, const std::vector<double> &ys)
{
    double total = ys[0];
    for(size_t i = 1; i < ys.size()-1; i++)
    {
        total += ys[i] * 2;
    }
    total += ys[ys.size()-1];
    total *= delta_x / 2;

    return total;
}