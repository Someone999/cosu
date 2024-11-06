//
// Created by HSMan on 24-11-5.
//

#ifndef OSUKPS_ITERATOR_H
#define OSUKPS_ITERATOR_H

#include <algorithm>
#include <optional>

namespace utils::iterator {
    template<typename TContainer, typename TElement>
    std::optional<TElement> find(TContainer &container, TElement element) {
        auto begin = container.cbegin();
        auto end = container.cend();
        auto result = std::find(begin, end, element);;
        if(result == end) {
            return std::nullopt;
        }

        return *result;
    }

    template<typename TContainer, typename TElement>
    void remove_one(TContainer &container, TElement element) {
        auto begin = container.begin();
        auto end = container.end();
        auto iter = std::find(begin, end, element);
        if (iter == end) {
            return;
        }

        if constexpr (std::is_same_v<typename std::iterator_traits<decltype(iter)>::iterator_category, std::random_access_iterator_tag>) {
            container.erase(iter, iter + 1);
        } else {
            container.erase(iter);
        }
    }

    template<typename TContainer, typename TElement>
    void remove_all(TContainer &container, TElement element) {
        auto begin = container.begin();
        auto end = container.end();
        auto iter = std::remove(begin, end, element);
        container.erase(iter, end);
    }
}


#endif //OSUKPS_ITERATOR_H
