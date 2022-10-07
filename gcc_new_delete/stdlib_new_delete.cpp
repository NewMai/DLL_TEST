//===--------------------- stdlib_new_delete.cpp --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//
// This file implements the new and delete operators.
//===----------------------------------------------------------------------===//

#include "__cxxabi_config.h"
#include <new>
#include <cstdlib>

#if defined(_LIBCPP_CXX03_LANG)
#define _THROW_BAD_ALLOC throw(std::bad_alloc)
#else
#define _THROW_BAD_ALLOC
#endif

#ifndef _LIBCPP_HAS_NO_NOEXCEPT
#  define _NOEXCEPT noexcept
#  define _NOEXCEPT_(x) noexcept(x)
#else
#  define _NOEXCEPT throw()
#  define _NOEXCEPT_(x)
#endif


enum class align_val_t: size_t {};

inline 
void __libcpp_aligned_free(void* __ptr) {
#if defined(_LIBCPP_MSVCRT_LIKE)
  ::_aligned_free(__ptr);
#else
  ::free(__ptr);
#endif
}

inline 
void* __libcpp_aligned_alloc(std::size_t __alignment, std::size_t __size) {
#if defined(_LIBCPP_MSVCRT_LIKE)
  return ::_aligned_malloc(__size, __alignment);
#else
  void* __result = nullptr;
  //::posix_memalign(&__result, __alignment, __size);
  // If posix_memalign fails, __result is unmodified so we still return `nullptr`.
  return __result;
#endif
}


#if !defined(_THROW_BAD_ALLOC)
#error The _THROW_BAD_ALLOC not define
#endif

#if !defined(_NOEXCEPT)
#error The _NOEXCEPT not define
#endif

#if !defined(_LIBCXXABI_WEAK)
#error The _LIBCXXABI_WEAK not define
#endif

#if !defined(_THROW_BAD_ALLOC) || !defined(_NOEXCEPT) || !defined(_LIBCXXABI_WEAK)
#error The _THROW_BAD_ALLOC, _NOEXCEPT, and _LIBCXXABI_WEAK libc++ macros must \
       already be defined by libc++.
#endif
// Implement all new and delete operators as weak definitions
// in this shared library, so that they can be overridden by programs
// that define non-weak copies of the functions.

_LIBCXXABI_WEAK
void *
operator new(std::size_t size) _THROW_BAD_ALLOC
{
    if (size == 0)
        size = 1;
    void* p;
    while ((p = ::malloc(size)) == nullptr)
    {
        // If malloc fails and there is a new_handler,
        // call it to try free up memory.
        std::new_handler nh = std::get_new_handler();
        if (nh)
            nh();
        else
#ifndef _LIBCXXABI_NO_EXCEPTIONS
            throw std::bad_alloc();
#else
            break;
#endif
    }
    return p;
}

_LIBCXXABI_WEAK
void*
operator new(size_t size, const std::nothrow_t&) _NOEXCEPT
{
    void* p = nullptr;
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    try
    {
#endif  // _LIBCXXABI_NO_EXCEPTIONS
        p = ::operator new(size);
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    }
    catch (...)
    {
    }
#endif  // _LIBCXXABI_NO_EXCEPTIONS
    return p;
}

_LIBCXXABI_WEAK
void*
operator new[](size_t size) _THROW_BAD_ALLOC
{
    return ::operator new(size);
}

_LIBCXXABI_WEAK
void*
operator new[](size_t size, const std::nothrow_t&) _NOEXCEPT
{
    void* p = nullptr;
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    try
    {
#endif  // _LIBCXXABI_NO_EXCEPTIONS
        p = ::operator new[](size);
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    }
    catch (...)
    {
    }
#endif  // _LIBCXXABI_NO_EXCEPTIONS
    return p;
}

_LIBCXXABI_WEAK
void
operator delete(void* ptr) _NOEXCEPT
{
    ::free(ptr);
}

_LIBCXXABI_WEAK
void
operator delete(void* ptr, const std::nothrow_t&) _NOEXCEPT
{
    ::operator delete(ptr);
}

_LIBCXXABI_WEAK
void
operator delete(void* ptr, size_t) _NOEXCEPT
{
    ::operator delete(ptr);
}

_LIBCXXABI_WEAK
void
operator delete[] (void* ptr) _NOEXCEPT
{
    ::operator delete(ptr);
}

_LIBCXXABI_WEAK
void
operator delete[] (void* ptr, const std::nothrow_t&) _NOEXCEPT
{
    ::operator delete[](ptr);
}

_LIBCXXABI_WEAK
void
operator delete[] (void* ptr, size_t) _NOEXCEPT
{
    ::operator delete[](ptr);
}

#if !defined(_LIBCPP_HAS_NO_LIBRARY_ALIGNED_ALLOCATION)

_LIBCXXABI_WEAK
void *
operator new(std::size_t size, align_val_t alignment) _THROW_BAD_ALLOC
{
    if (size == 0)
        size = 1;
    if (static_cast<size_t>(alignment) < sizeof(void*))
      alignment = align_val_t(sizeof(void*));

    // Try allocating memory. If allocation fails and there is a new_handler,
    // call it to try free up memory, and try again until it succeeds, or until
    // the new_handler decides to terminate.
    //
    // If allocation fails and there is no new_handler, we throw bad_alloc
    // (or return nullptr if exceptions are disabled).
    void* p;
    while ((p = __libcpp_aligned_alloc(static_cast<std::size_t>(alignment), size)) == nullptr)
    {
        std::new_handler nh = std::get_new_handler();
        if (nh)
            nh();
        else {
#ifndef _LIBCXXABI_NO_EXCEPTIONS
            throw std::bad_alloc();
#else
            break;
#endif
        }
    }
    return p;
}

_LIBCXXABI_WEAK
void*
operator new(size_t size, align_val_t alignment, const std::nothrow_t&) _NOEXCEPT
{
    void* p = nullptr;
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    try
    {
#endif  // _LIBCXXABI_NO_EXCEPTIONS
        p = ::operator new(size, alignment);
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    }
    catch (...)
    {
    }
#endif  // _LIBCXXABI_NO_EXCEPTIONS
    return p;
}

_LIBCXXABI_WEAK
void*
operator new[](size_t size, align_val_t alignment) _THROW_BAD_ALLOC
{
    return ::operator new(size, alignment);
}

_LIBCXXABI_WEAK
void*
operator new[](size_t size, align_val_t alignment, const std::nothrow_t&) _NOEXCEPT
{
    void* p = nullptr;
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    try
    {
#endif  // _LIBCXXABI_NO_EXCEPTIONS
        p = ::operator new[](size, alignment);
#ifndef _LIBCXXABI_NO_EXCEPTIONS
    }
    catch (...)
    {
    }
#endif  // _LIBCXXABI_NO_EXCEPTIONS
    return p;
}

_LIBCXXABI_WEAK
void
operator delete(void* ptr, align_val_t) _NOEXCEPT
{
    __libcpp_aligned_free(ptr);
}

_LIBCXXABI_WEAK
void
operator delete(void* ptr, align_val_t alignment, const std::nothrow_t&) _NOEXCEPT
{
    ::operator delete(ptr, alignment);
}

_LIBCXXABI_WEAK
void
operator delete(void* ptr, size_t, align_val_t alignment) _NOEXCEPT
{
    ::operator delete(ptr, alignment);
}

_LIBCXXABI_WEAK
void
operator delete[] (void* ptr, align_val_t alignment) _NOEXCEPT
{
    ::operator delete(ptr, alignment);
}

_LIBCXXABI_WEAK
void
operator delete[] (void* ptr, align_val_t alignment, const std::nothrow_t&) _NOEXCEPT
{
    ::operator delete[](ptr, alignment);
}

_LIBCXXABI_WEAK
void
operator delete[] (void* ptr, size_t, align_val_t alignment) _NOEXCEPT
{
    ::operator delete[](ptr, alignment);
}

#endif // !_LIBCPP_HAS_NO_LIBRARY_ALIGNED_ALLOCATION