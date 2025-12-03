
#include <pico/stdlib.h>
#include <stdio.h>

#include <util/CStringStream.h>
#include <util/StringStreamLite.h>

#include <util/BufferView.h>
#include <util/UniqueArray.h>

int main()
{
    stdio_init_all();

    CStringStream<256> css;

    css << "hello";

    css << 8 << 9;

    StringStreamLite ssl;

    ssl << 9 << 8 << 7 << "test";

    std::unique_ptr<int[]> ar = std::make_unique<int[]>(5);
    
    UniqueArray<int> arr = make_unique_array<int>(std::move(ar), 5);

    while (1)
    {
        printf("%s\n", css.GetCString());
        printf("%s\n", ssl.GetCString());
    }

}