#pragma once
#include "memory_backend.h"
#include "memory_traits.h"

// for single element
namespace kun::memory
{
// construct & destruct
template<typename T> KUN_INLINE void construct(T* p)
{
    if constexpr (memory_traits<T>::call_ctor)
    {
        new (p) T();
    }
}
template<typename T> KUN_INLINE void destruct(T* p)
{
    if constexpr (memory_traits<T>::call_dtor)
    {
        using DestructItemTTypeDef = T;

        p->DestructItemTTypeDef::~DestructItemTTypeDef();
    }
}

// copy & assign
template<typename Dst, typename Src> KUN_INLINE void copy(Dst* dst, Src* src)
{
    if (dst != src)
    {
        if constexpr (memory_traits<Dst, Src>::call_copy)
        {
            new (dst) Dst(*src);
        }
        else
        {
            memory::memcpy(dst, src, sizeof(Src));
        }
    }
}
template<typename Dst, typename Src> KUN_INLINE void assign(Dst* dst, Src* src)
{
    if (dst != src)
    {
        if constexpr (memory_traits<Dst, Src>::call_assign)
        {
            *dst = *src;
        }
        else
        {
            memory::memcpy(dst, src, sizeof(Src));
        }
    }
}

// move copy & move assign
template<typename Dst, typename Src> KUN_INLINE void move(Dst* dst, Src* src)
{
    if (dst != src)
    {
        if constexpr (memory_traits<Dst, Src>::call_move)
        {
            new (dst) Dst(std::move(*src));
        }
        else
        {
            memory::memcpy(dst, src, sizeof(Src));
        }
    }
}
template<typename Dst, typename Src> KUN_INLINE void moveAssign(Dst* dst, Src* src)
{
    if (dst != src)
    {
        if constexpr (memory_traits<Dst, Src>::call_move_assign)
        {
            *dst = std::move(*src);
        }
        else
        {
            memory::memcpy(dst, src);
        }
    }
}

// compare
template<typename A, typename B> KUN_INLINE bool compare(const A* a, const B* b)
{
    if constexpr (memory_traits<A, B>::call_compare)
    {
        return *a != *b;
    }
    else
    {
        static_assert(sizeof(A) == sizeof(B), "keep sizeof(A) == sizeof(B) if you want use memcmp");
        return !memcmp(a, b, sizeof(B));
    }
}
}// namespace kun::memory

// for multi elements
namespace kun::memory
{
// construct & destruct
template<typename T> KUN_INLINE void construct(T* p, Size count)
{
    if constexpr (memory_traits<T>::call_ctor)
    {
        while (count)
        {
            new (p) T();
            ++p;
            --count;
        }
    }
}
template<typename T> KUN_INLINE void destruct(T* p, Size count)
{
    if constexpr (memory_traits<T>::call_dtor)
    {
        while (count)
        {
            using DestructItemTTypeDef = T;

            p->DestructItemTTypeDef::~DestructItemTTypeDef();
            ++p;
            --count;
        }
    }
}

// copy & assign
template<typename Dst, typename Src> KUN_INLINE void copy(Dst* dst, Src* src, Size count)
{
    if constexpr (memory_traits<Dst, Src>::call_copy)
    {
        while (count)
        {
            new (dst) Dst(*src);
            ++dst;
            ++src;
            --count;
        }
    }
    else
    {
        memory::memcpy(dst, src, sizeof(Src) * count);
    }
}
template<typename Dst, typename Src> KUN_INLINE void assign(Dst* dst, Src* src, Size count)
{
    if constexpr (memory_traits<Dst, Src>::call_assign)
    {
        while (count)
        {
            *dst = *src;
            ++dst;
            ++src;
            --count;
        }
    }
    else
    {
        memory::memcpy(dst, src, sizeof(Src) * count);
    }
}

// move copy & move assign
template<typename Dst, typename Src> KUN_INLINE void move(Dst* dst, Src* src, Size count)
{
    if constexpr (memory_traits<Dst, Src>::call_move)
    {
        if (dst < src)
        {
            while (count)
            {
                new (dst) Dst(std::move(*src));
                ++dst;
                ++src;
                --count;
            }
        }
        else if (dst > src)
        {
            auto dst_end = dst + count;
            auto src_end = src + count;

            while (count)
            {
                new (dst_end) Dst(std::move(*src_end));
                --dst_end;
                --src_end;
                --count;
            }
        }
    }
    else
    {
        memory::memmove(dst, src, sizeof(Src) * count);
    }
}
template<typename Dst, typename Src> KUN_INLINE void moveAssign(Dst* dst, Src* src, Size count)
{
    if constexpr (memory_traits<Dst, Src>::call_move_assign)
    {
        if (dst < src)
        {
            while (count)
            {
                *dst = std::move(*src);
                ++dst;
                ++src;
                --count;
            }
        }
        else if (dst > src)
        {
            auto dst_end = dst + count;
            auto src_end = src + count;

            while (count)
            {
                *dst_end = std::move(*src_end);
                --dst_end;
                --src_end;
                --count;
            }
        }
    }
    else
    {
        memory::memmove(dst, src, sizeof(Src) * count);
    }
}

// compare
template<typename A, typename B> KUN_INLINE bool compare(const A* a, const B* b, Size count)
{
    if constexpr (memory_traits<A, B>::call_compare)
    {
        while (count)
        {
            if (*a != *b)
            {
                return false;
            }

            ++a;
            ++b;
            --count;
        }
        return true;
    }
    else
    {
        return !memcmp(a, b, sizeof(B) * count);
    }
}

}