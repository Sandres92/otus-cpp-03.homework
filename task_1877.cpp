#include "task_1877.h"

namespace otus
{
    bool task_1877(const std::vector<int> &code1, const std::vector<int> &code2)
    {

        auto vectorToNumber = [](const std::vector<int> &codeVec) -> unsigned int
        {
            unsigned int code = 0;
            int multiplayer = 10;
            for (size_t i = 0; i != codeVec.size(); ++i)
            {
                code *= multiplayer;
                // multiplayer *= 10;
                code += codeVec[i];
            }

            return code;
        };

        unsigned int number1 = vectorToNumber(code1);
        unsigned int number2 = vectorToNumber(code2);

        if (number1 % 2 == 0 || number2 % 2 != 0)
        {
            return true;
        }

        return false;
    }
} // namespace otus
