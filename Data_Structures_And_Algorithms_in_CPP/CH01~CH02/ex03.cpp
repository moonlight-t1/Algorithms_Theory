// copy constructor
Vect::Vect(const Vect& a)
{
    size = a.size;
    data = new int[data];
    for (int i = 0; i < size; i++)
    {
        data[i] = a.data[i];
    }
}

// assignment opeartor
Vect& Vect::operator==(const Vect& a)
{
    if (this != &a)
    {
        delete[] data;
        size = a.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = a.data[i];
        }
        return *this;
    }
}