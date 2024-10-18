#include "person.h"

Person::Person(float height, float weight)
    : P(height), M(weight)
{
    if (height <= 50 || height >= 300)
    {
        throw "Рост должен быть от 50 до 300 см.";
    }

    if (weight <= 10 || weight >= 500)
    {
        throw "Масса должна быть от 10 до 500 кг.";
    }
}

float Person::getHeight() const
{
    return P;
}

float Person::getWeight() const
{
    return M;
}

float Person::calculateBMI() const
{
    return M / std::pow(P / 100.0, 2);
}

QString Person::getBMICategory() const
{
    float bmi = calculateBMI();

    if (bmi < 18.5)
    {
        return "недостаточный вес";
    } else if (bmi >= 18.5 && bmi < 24.9)
    {
        return "норма";
    } else if (bmi >= 25 && bmi < 29.9)
    {
        return "избыточный вес";
    } else
    {
        return "ожирение";
    }
}
