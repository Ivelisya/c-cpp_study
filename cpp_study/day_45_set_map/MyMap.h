#pragma once
#include "RBTree.h"
namespace bit
{
    template <class K, class V>
    class map
    {
    public:
        struct MapKeyOfT

        {
            /* data */
        };

    private:
        RBTree < K, pair<K, V> _t;
    };
}