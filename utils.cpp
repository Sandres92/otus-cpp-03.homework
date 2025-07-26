#include "utils.h"

namespace otus
{
    namespace utils
    {
        int factorial(int number)
        {
            if (number == 0)
            {
                return 0;
            }

            int result = 1;
            for (int i = 1; i <= number; ++i)
            {
                result *= i;
            }

            return result;
        }
    }
}