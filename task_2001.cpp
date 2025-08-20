#include "task_2001.h"
#include <stdexcept>

namespace otus
{
    std::vector<unsigned int> task_2001(const std::vector<unsigned int> &allMass,
                                        const std::vector<unsigned int> &inFirstBasket,
                                        const std::vector<unsigned int> &inSecondBasket)
    {
        if (allMass.size() < 2)
        {
            throw std::invalid_argument("task_2001 not enough data");
        }

        std::vector<unsigned int> result(allMass.size());

        for (size_t i = 1; i != allMass.size(); ++i)
        {
            result[i] = allMass[i] - inFirstBasket[i];
        }
        result[0] = allMass[0] - inSecondBasket[0];

        return result;
    }
}