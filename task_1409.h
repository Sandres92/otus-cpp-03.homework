#include <iostream>
#include <tuple>
#include <utility>
#include <type_traits>

namespace otus
{
    // std::tuple<int, int> task_1409(std::tuple<int, int> shots);

    template <typename... Args>
    auto SumShots(Args... args)
    {
        static_assert((std::is_same_v<Args, unsigned int> && ...), "All arguments must be int");
        return (args + ...);
    }

    template <typename... Args>
    std::tuple<Args...> task_1409_vt(Args... shots)
    {
        static_assert((std::is_same_v<Args, unsigned int> && ...), "All arguments must be int");

        int sumShots = SumShots(shots...);
        if (sumShots == 0)
        {
            return std::make_tuple((0 * shots)...);
        }
        if (sumShots != 1)
        {
            --sumShots;
        }

        return std::make_tuple((sumShots - shots)...);
    }
}