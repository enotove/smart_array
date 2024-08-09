#include <iostream>
#include <string>

class Smart_array {
public:
    Smart_array(int a)
    {
        arr = new int[a];
        size = a;
    }
    
    void add_element(int value)
    {
        if (arr == nullptr) throw std::exception("You're not make the array!");
        else if (counter == size) throw std::exception("You fill in the array, that's enough");
        arr[counter] = value;
        counter++;

    }
    int get_element(int index)
    {
        if (index >= size || index < 0)
        {
            throw std::exception("Going outside the array");
        };

        return arr[index];
    }
    ~Smart_array()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            counter = 0;
            arr = nullptr;
        }
    }

    
private:
    int* arr{ nullptr };
    int counter = 0;
    int size;

};

int main()
{
    try {
        Smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(4) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

