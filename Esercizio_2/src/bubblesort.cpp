#include <iostream>
#include <vector>

template<typename T>
void print(const std::vector<T>& vs)
{
    for (auto & v : vs)
        std::cout << v << " ";
    std::cout << std::endl;
}

template<typename T>
void
bubblesort(std::vector<T>& data)
{
    size_t rem_size = data.size();
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (size_t i = 1; i < rem_size; i++) {
            if (data[i-1] > data[i]) {
                std::swap(data[i-1], data[i]);
                swapped = true;
            }
        }
        rem_size = rem_size - 1;
    }
}

int main(void)
{
    std::vector<int> int_vs = { 4, 6, 3, 5, 2, 1 };
    
    bubblesort(int_vs);
    print(int_vs);

    std::vector<std::string> str_vs = {
        "delta", "foxtrot", "charlie",
        "echo", "bravo", "alpha"
    };

    bubblesort(str_vs);
    print(str_vs);

    return 0;
}

