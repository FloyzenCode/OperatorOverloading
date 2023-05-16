#include <iostream>
#include <thread>
#include <chrono>

class SleepOperator {
public:
    SleepOperator(std::string str) {
        str_ = str;
    }
    void print() {
        std::cout << str_;
    }
    SleepOperator& operator<<(const std::string& str) {
        for (size_t i = 0; i < str.size(); i++) {
            std::cout << str[i];
            std::this_thread::sleep_for(std::chrono::milliseconds(40));
        }
        return *this;
    }
private:
    std::string str_;
};

class Counter
{
public:
    Counter(int val)
    {
        value = val;
    }
    void print()
    {
        std::cout << "Value: " << value << std::endl;
    }
    bool operator == (const Counter& counter) const
    {
        return value == counter.value;
    }
    bool operator != (const Counter& counter) const
    {
        return value != counter.value;
    }
    bool operator > (const Counter& counter) const
    {
        return value > counter.value;
    }
    bool operator < (const Counter& counter) const
    {
        return value < counter.value;
    }
private:
    int value;
};

class OperatorOutput
{
public:
    OperatorOutput(int val)
    {
        value = val;
    }
    int getValue() const { return value; }
private:
    int value;
};

std::ostream& operator<<(std::ostream& stream, const OperatorOutput& counter)
{
    stream << "Value: ";
    stream << counter.getValue();
    return stream;
}



int main()
{
    SleepOperator v{ "" };
    v << "Hello world!";

    /* Counter example */
    Counter c1(20);
    Counter c2(10);
    bool b1 = c1 == c2;     // false
    bool b2 = c1 > c2;   // true

    std::cout << "c1 == c2 = " << std::boolalpha << b1 << std::endl;    // c1 == c2 = false
    std::cout << "c1 > c2 = " << std::boolalpha << b2 << std::endl;     // c1 > c2 = true

    /* OperatorOutput */
    OperatorOutput counter1{ 20 };
    OperatorOutput counter2{ 50 };
    std::cout << counter1 << std::endl;     // Value: 20
    std::cout << counter2 << std::endl;     // Value: 50

    return 0;
}

/*
* 
* more example
* 
    class Counter
{
public:
    Counter(int val)
    {
        value = val;
    }
    void print()
    {
        std::cout << "Value: " << value << std::endl;
    }
    Counter operator + (const Counter& counter) const
    {
        return Counter{ value + counter.value };
    }
private:
    int value;
};
*/