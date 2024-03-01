#include <array>
#include <memory>
#include <iostream>

static int counter = 0;

class Bar {
public:
    std::array<int, 30> not_important_;
};

class Foo {
public:
    Foo() : unique_bar_{std::make_unique<Bar>()}, index{counter++}, shared_bar_{std::make_shared<Bar>()} {
        std::cout << "foo_" << index << ": Constructor called" << std::endl;
    }

    // Rule of three!
    Foo(const Foo& rhs) : unique_bar_{std::make_unique<Bar>()}, index{counter++} {
        shared_bar_ = rhs.shared_bar_;
        std::cout << "foo_" << index << ": Copy constructor called" << std::endl;
        for (int i = 0; i < 30; i++) {
            unique_bar_->not_important_[i] = rhs.unique_bar_->not_important_[i];
        }
    }

    Foo& operator=(const Foo& rhs) {
    // void operator=(const Foo& rhs) {
        std::cout << "foo_" << index << ": Assignment operator called" << std::endl;
        if (this != &rhs){
            return *(new Foo(rhs));
        }else{
            return *this;
        }
    }

    ~Foo() {
        std::cout << "foo_" << index << ": Destructor called" << std::endl;
    }

private:
    std::unique_ptr<Bar> unique_bar_{nullptr};
    std::shared_ptr<Bar> shared_bar_{nullptr};
    int index;
};

int main() {
    Foo foo_0;
    Foo foo_1 = foo_0;
    Foo foo_2;

    foo_2 = foo_1 = foo_0;

    std::cout << "foo_0 address: " << &foo_0 << std::endl;
    std::cout << "foo_1 address: " << &foo_1 << std::endl;
    std::cout << "foo_2 address: " << &foo_2 << std::endl;

    return 0;
}