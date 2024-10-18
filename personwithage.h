#ifndef PERSONWITHAGE_H
#define PERSONWITHAGE_H

#include "person.h"

class PersonWithAge : public Person
{
private:
    int B;

public:
    PersonWithAge(float height, float weight, int age);
    int getAge() const;
    float calculateBMR() const;
    void calculateMacronutrients(float& proteins, float& fats, float& carbs) const;
};

#endif // PERSONWITHAGE_H
