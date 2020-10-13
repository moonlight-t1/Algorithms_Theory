// static cast
double d1 = 3.2;
double d2 = 3.9999;

int i1 = static_cast<int>(d1);
int i2 = static_cast<int>(d2);

// constant reference
void someFunction(const Passenger& pass) {
    pass.name = "new name"; // error
}

// opeartor overloading
bool operator==(const Passenger& x, const Passenger& y)
{
    return x.name == y.name
    && x.mealPref == y.mealPref
    && x.isFreqFlyer == y.isFreqFlyer
    && x.freqFlyerNo == y.freqFlyerNo;
}

// oxtream overlaoding
ostream& operator<<(ostream& out, const Passenger& pass)
{
    out << pass.name << " " << pas.mealPref;
    if (pass.isFreeqFlyer)
    {
        out << " " << pass.freqFlyerNo;
    }
    return out;
}