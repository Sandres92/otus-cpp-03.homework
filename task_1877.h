#include <vector>

namespace otus
{
    // template <typename... Args>
    // auto ToSingleNumber(Args... args)
    //{
    //     static_assert((std::is_same_v<Args, unsigned int> && ...), "All arguments must be int");
    //     static_assert(((code1 >= 0 && code1 <= 9) && ...), "All numbers must be between 0 and 9.");
    //     static_assert(((code2 >= 0 && code2 <= 9) && ...), "All numbers must be between 0 and 9.");
    //
    //    return (((args * 10 + ...)) + 0);
    //}
    //
    // template <typename... Args>
    // bool task_1877_vt(std::tuple<Args...> code1, std::tuple<Args...> code2)
    //{
    //    static_assert((std::is_same_v<Args, unsigned int> && ...), "All arguments must be int");
    //    static_assert(((code1 >= 0 && code1 <= 9) && ...), "All numbers must be between 0 and 9.");
    //    static_assert(((code2 >= 0 && code2 <= 9) && ...), "All numbers must be between 0 and 9.");
    //
    //    unsigned int number1 = ToSingleNumber(code1...);
    //    unsigned int number2 = ToSingleNumber(code2...);
    //
    //    if (number1 == 0)
    //    {
    //        return true;
    //    }
    //    else if (number2 == 0)
    //    {
    //        return false;
    //    }
    //    else if (number1 % 2 == 0 || number2 % 2 != 0)
    //    {
    //        return true;
    //    }
    //
    //    return false;
    //}
    bool task_1877(const std::vector<int> &code1, const std::vector<int> &code2);
}