#pragma once

#ifndef KUN_IMPL_ASSERT_FUNCS

    #include <iostream>

namespace kun
{
KUN_INLINE void dumpAssert(const char* assert, const char* message, const char* file, Size line)
{
    // log error
    ::std::cerr << "Assert Failed!!!\n"
                << "Error:\t\t" << assert << "\n";

    // source file
    ::std::cerr << "Source:\t\t" << file << "(line: " << line << ")\n";

    // log message
    if (message)
    {
        ::std::cerr << "Message:\t\t" << message << std::endl;
    }
}
KUN_INLINE void dumpVerify(const char* verify, const char* message, const char* file, Size line)
{
    // log error
    ::std::cerr << "Verify Failed!!!\n"
                << "Error:\t\t" << verify << "\n";

    // source file
    ::std::cerr << "Source:\t\t" << file << "(line: " << line << ")\n";

    // log message
    if (message)
    {
        ::std::cerr << "Message:\t\t" << message << std::endl;
    }
}
}// namespace kun

#endif
