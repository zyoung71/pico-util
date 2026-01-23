#pragma once

template<typename Single, typename Many>
union ByteSplitter
{
    static_assert(sizeof(Single) % sizeof(Many) == 0);

    Single single;
    Many many[sizeof(Single)/sizeof(Many)];
};
template<typename Many, typename Single>
using ByteCombiner = ByteSplitter<Single, Many>;