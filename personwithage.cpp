#include "personwithage.h"

PersonWithAge::PersonWithAge(float height, float weight, int age)
    : Person(height, weight), B(age)
{
    if (age <= 0 || age >= 120)
    {
        throw "Возраст должен быть от 0 до 120 лет.";
    }
}

int PersonWithAge::getAge() const
{
    return B;
}

float PersonWithAge::calculateBMR() const
{
    return (6.25 * P + 10 * M - 4.92 * B);
}

void PersonWithAge::calculateMacronutrients(float& proteins, float& fats, float& carbs) const
{
    float bmr = calculateBMR();

    proteins = (bmr * 0.3) / 4;
    fats = (bmr * 0.25) / 9;
    carbs = (bmr * 0.45) / 4;
}
