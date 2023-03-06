#include "class.h"

Thermometer::Thermometer(double temp)
{
    tempCelsius=temp;
    SetTempCelsius(temp);
}
void Thermometer::SetTempCelsius(double tempCelsius)
{
    tempCelsius=tempCelsius;
    tempFahrenheit=32+tempCelsius*1.8;
}
void Thermometer::SetTempFahrenheit(double tempFahrenheit)
{
    tempFahrenheit=tempFahrenheit;
    tempCelsius=(tempFahrenheit-32)/1.8;
}

double Thermometer::GetTempCelsius()
{
    return tempCelsius;
}
double Thermometer::GetTempFahrenheit()
{
    return tempFahrenheit;
}
