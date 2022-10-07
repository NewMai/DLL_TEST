
#include <new>
#include <cstdlib>

#define _LIBCXXABI_WEAK
#define _THROW_BAD_ALLOC
#define _NOEXCEPT

_LIBCXXABI_WEAK
void*
operator new[](size_t size) _THROW_BAD_ALLOC
{
    return ::operator new(size);
}


_LIBCXXABI_WEAK
void
operator delete[] (void* ptr) _NOEXCEPT
{
    ::operator delete(ptr);
}


