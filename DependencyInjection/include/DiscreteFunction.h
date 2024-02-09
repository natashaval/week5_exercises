#pragma once 
#include <memory>
#include <vector>
#include <functional>

class Integrator {
    public:
    // Integrator();

    // create pure virtual function to make it an abstract class
    virtual double integrate(const double delta_x, const std::vector<double> &ys) = 0;
};

class SimpsonIntegrator : public Integrator
{
    public:
    SimpsonIntegrator();

    double integrate(const double delta_x, const std::vector<double> &ys);
};

class TrapeziumIntegrator : public Integrator
{
    public:
    TrapeziumIntegrator();

    double integrate(const double delta_x, const std::vector<double> &ys);
};

class DiscreteFunction
{
    public:
    DiscreteFunction(std::vector<double> y, double x_min, double x_max);
    DiscreteFunction(std::vector<double> y, double x_min, double x_max, std::unique_ptr<Integrator> &integratorPtr);

    double integrate();
    void setIntegrator(std::unique_ptr<Integrator> &integratorPtr);

    private:
    std::unique_ptr<Integrator> integrator;
    std::vector<double> ys;
    double min_x;
    double max_x;
    double delta_x;
    void initializeValue(std::vector<double> y);
};

