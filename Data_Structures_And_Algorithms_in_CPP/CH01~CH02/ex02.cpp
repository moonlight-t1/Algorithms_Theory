class Passenger
{
public:
    Passenger(); // constructor
    bool isFrequentFlyer() const; // access function
    void makeFrequentFlyer(const string& newFreqFlyerNo); // const reference

private:
    string anme;
    MealType mealPref;
    bool isFreqFlyer;
    string freqFlyerNo;
};