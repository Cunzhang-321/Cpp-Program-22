#ifndef CLASS_H
#define CLASS_H

class Thermometer
{
private:
    double tempCelsius;
    double tempFahrenheit;
public:
    // constructor (default Celsius)
    Thermometer();
    Thermometer(double temp);
    //~Thermometer();  //该函数为析构函数，暂时未讲到，不需要实现

    // set temperature
    void SetTempCelsius(double tempCelsius);
    void SetTempFahrenheit(double tempFahrenheit);

    // display temperature
    double GetTempCelsius();
    double GetTempFahrenheit();
};



#endif /* CLASS_H */
