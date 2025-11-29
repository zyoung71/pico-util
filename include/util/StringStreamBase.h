#pragma once

// Base class for implemented string stream classes.
// Separate file to avoid include clutter. You pay for what you use.
class StringStreamBase
{
public:
    virtual ~StringStreamBase() = default;

    virtual const char* GetCString() const = 0;
};