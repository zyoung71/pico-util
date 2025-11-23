#pragma once

template<typename Single, typename Many>
union ByteSplitter
{
    static_assert(sizeof(Many) % sizeof(Single) == 0);

    Single single;
    Many many[sizeof(Single)/sizeof(Many)];
};
template<typename Single, typename Many>
using ByteCombiner = ByteSplitter<Single, Many>;