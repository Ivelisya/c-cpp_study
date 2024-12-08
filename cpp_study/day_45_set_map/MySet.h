#pragma once
#include "RBTree.h"
namespace bit
{
    template <class K>
    class map
    {

    private:
        RBTree<K, K> _t;
    };
}