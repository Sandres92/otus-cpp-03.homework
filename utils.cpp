#pragma once

namespace otus
{
    namespace utils
    {
        int factorial(int number)
        {
            int result = 0;
            for (int i = 1; i <= number; ++i)
            {
                result *= i;
            }

            return result;
        }
    }
}