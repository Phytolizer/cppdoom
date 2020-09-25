//
// Created by kyle on 9/24/20.
//

#ifndef EZ_BOOM_MAP_HH
#define EZ_BOOM_MAP_HH

#include <tuple>

namespace map
{

template <typename K, typename V, size_t Sz> struct map
{
    std::array<std::pair<K, V>, Sz> m;

    constexpr V& at(const K& key)
    {
        auto* iter = std::find_if(m.begin(), m.end(), [&key](auto& v) { return v.first == key; });
        if (iter != m.end())
        {
            return iter->second;
        }
        throw std::range_error("not found");
    }
};

} // namespace map

#endif // EZ_BOOM_MAP_HH
