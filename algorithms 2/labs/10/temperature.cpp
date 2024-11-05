#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature() {
  kelvin_ = 0;
}

Temperature::Temperature(double kelvin) {
  kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit) {
  if ('C' == unit || 'c' == unit) {
    SetTempFromCelsius(temp);
  } else if ('F' == unit || 'f' == unit) {
    SetTempFromFahrenheit(temp);
  } else {
    SetTempFromKelvin(temp);
  }
}

void Temperature::SetTempFromKelvin(double kelvin) {
    kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius) {
    kelvin_ = celsius + 273.15;
}

void Temperature::SetTempFromFahrenheit(double fahrenheit) {
    kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
}

double Temperature::GetTempAsKelvin() const {
  //double kelvin = kelvin_;
  return kelvin_;
}

double Temperature::GetTempAsCelsius() const {
    double Celcius = kelvin_-273.15;
    return Celcius;
}

double Temperature::GetTempAsFahrenheit() const {
    double Fahrenheit = ((GetTempAsCelsius() * 9.0) / 5) + 32;
    return Fahrenheit;
}

string Temperature::ToString(char unit) const {
  std::stringstream ss;
  if (unit == 'K' || unit == 'k') {
    ss << std::fixed << std::setprecision(2) << GetTempAsKelvin() << " Kelvin";
  } else if (unit == 'F' || unit == 'f') {
    ss << std::fixed << std::setprecision(2) << GetTempAsFahrenheit() << " Fahrenheit";
  } else if (unit == 'C' || unit == 'c') {
    ss << std::fixed << std::setprecision(2) << GetTempAsCelsius() << " Celsius";
  } else {
    ss << "Invalid Unit";
  }
  return ss.str();
}