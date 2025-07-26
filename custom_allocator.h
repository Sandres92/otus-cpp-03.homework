#pragma once
#include <iostream>

namespace otus
{
    template <class T, size_t size>
    class CustomAllocator
    {
        using value_type = T;

        using pointer = T *;
        using const_pointer = const T *;
        using reference = T &;
        using const_reference = const T &;

        CustomAllocator() : current(0) = default;

        template <class U>
        CustomAllocator(const CustomAllocator<T> &other) = default;

        T *allocate(std::size_t n)
        {
            if (n == 0)
            {
                std::invalid_argument("invalid_argument size alloc");
            }

            if (position + n > size)
            {
                std::bad_alloc();
            }

            T *p = reinterpret_cast<T *>(&buffer[position]);
            position += n;
            return p;
        }

        void deallocate(T *p, std::size_t n)
        {
        }

        template <typename U, typename... Args>
        void construct(U *p, Args &&...args)
        {
            new (p) U(std::forward<Args>(args)...);
        };

        template <typename U>
        void destroy(U *p)
        {
            p->~U();
        }

    private:
        alignas(T) char buffer[size * sizeof(T)];
        size_t position = 0;
    };
}