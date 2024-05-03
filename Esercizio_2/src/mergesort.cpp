#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
void print(const std::vector<T>& vs)
{
    for (auto & v : vs)
        std::cout << v << " ";
    std::cout << std::endl;
}


namespace detail {

template<typename T>
void
merge(std::vector<T>& data, size_t left, size_t center, size_t right)
{
    assert(right >= left);
    size_t i = left;
    size_t j = center+1;
    size_t k = 0;

    std::vector<T> tmp(right - left + 1);

    while (i <= center && j <= right) {
        if (data[i] <= data[j]) {
            assert(k < tmp.size());
            assert(i < data.size());
            tmp[k++] = data[i++];
        }
        else {
            assert(k < tmp.size());
            assert(j < data.size());
            tmp[k++] = data[j++];
        }
    }

    while (i <= center) {
        assert(k < tmp.size());
        assert(i < data.size());
        tmp[k++] = data[i++];
    }

    while (j <= right) {
        assert(k < tmp.size());
        assert(j < data.size());
        tmp[k++] = data[j++];
    }

    assert(k == (right - left + 1));

    for (size_t h = left; h <= right; h++)
        data[h] = tmp[h-left];
}

template<typename T>
void
mergesort(std::vector<T>& data, size_t left, size_t right)
{
    assert(left <= data.size());
    assert(right <= data.size());

    if (left < right) {
        size_t center = (left + right)/2;
        mergesort(data, left, center);
        mergesort(data, center+1, right);
        /* Ipotesi induttiva: [left, center] e
         * [center+1, right] sono ordinati.
         * Assumo merge() corretta */
        merge(data, left, center, right);
        /* Qui [left,right] è ordinato */
    }
    /* Caso base: il vettore di un solo elemento è ordinato */
}

} // namespace detail

template<typename T>
void
mergesort(std::vector<T>& data)
{
    detail::mergesort(data, 0, data.size()-1);
}

int main(void)
{
    std::vector<int> int_vs = { 4, 6, 3, 5, 2, 1 };
    
    mergesort(int_vs);
    print(int_vs);

    std::vector<std::string> str_vs = {
        "delta", "foxtrot", "charlie",
        "echo", "bravo", "alpha"
    };

    mergesort(str_vs);
    print(str_vs);

    return 0;
}

