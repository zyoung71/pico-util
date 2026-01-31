
#include <pico/stdlib.h>
#include <stdio.h>

#include <util/CStringStream.h>
#include <util/StringStreamLite.h>

#include <util/BufferView.h>
#include <util/UniqueArray.h>
#include <util/ArraySupplier.h>
#include <util/ByteSplitter.h>

#include <util/FilesystemTree.h>

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

    FilesystemTree fs;
    FilesystemNodeData user_folder = {"users", true};
    fs.AddNode(user_folder);
    fs.RemoveNode(user_folder);

    ByteSplitter<uint32_t, uint8_t> split;

    ArraySupplier<int, 5> as;
    as[0] = 0;
    as[1] = 1;

    // as.At<90>() = 7; // Will fail

    // use At<idx>() for compile-time and runtime, use [idx] for only runtime

    while (1)
    {
        printf("%s\n", css.GetCString());
        printf("%s\n", ssl.GetCString());
    }

}