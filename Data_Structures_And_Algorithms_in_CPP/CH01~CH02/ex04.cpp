Person* pp[100];
pp[0] = new Person(...); // Person 한명 추가
pp[1] = new Student(...); // Student 한명 추가

cout << pp[1]->getName() << '\n';
pp[0]->print(); // Person::print() 호출
pp[1]->print(); // Person::print() 호출
pp[1]->changeMajor("English"); // Error


class Person {
    virtual void print() {...}; // virtual
}

class Student {
    virtual void print() {...}; // virtual
}

Person* pp[100];
pp[0] = new Person(...); // Person 한명 추가
pp[1] = new Student(...); // Student 한명 추가

pp[0]->print(); // Person::print() 호출
pp[1]->print(); // Student::print() 호출