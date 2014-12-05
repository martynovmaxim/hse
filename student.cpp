#include <iostream>
#include <string>
#include <vector>

/*class Car {
    private:
        double speed;
    public:
        Car(double speed): speed(speed) {
        }

        void set_speed(double new_speed) {
            speed = new_speed;
        }
        void set_wheel_freq(double new_freq) {
            speed = new_freq / 10.0;
        }
        double get_speed(void) {
            return speed;
        }
        double get_wheel_freq(void) {
            return speed * 10.0;
        }

        void print(void) {
            std::cout << "speed: " << get_speed() << "; wheel freq: " << get_wheel_freq() << std::endl;
        }
};*/

template<class T> class Student {
    private:
        std::string name, surname;
    public:
        T age;
        Student(const std::string& name, const std::string& surname, T age): name(name), surname(surname), age(age) {
        }
        const std::string& get_name(void) {
            return name;
        }
        const std::string& get_surname(void) {
            return surname;
        }

        bool operator ==(const Student& other) const {
            return name == other.name && surname == other.surname;
        }
};

template<> class Student<int> {
};

int main(void) {
    int i[100];
    i = nullptr;
    /*Student<int> a("qwe", "asd", 123), b("zxc", "rty", 456);
    Student<int> c = a;
    std::cout << (a == b) << ' ' << (a == c) << ' ' << (b == c) << std::endl;*/
    return 0;
}
