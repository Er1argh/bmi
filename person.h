#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <cmath>

class Person
{
protected:
    float P;
    float M;

public:
    Person(float height, float weight);
    float getHeight() const;
    float getWeight() const;
    float calculateBMI() const;
    QString getBMICategory() const;
};

#endif // PERSON_H
