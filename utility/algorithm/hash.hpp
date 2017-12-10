
#ifndef __UTILITY_ALGORITHM_HASH__
#define __UTILITY_ALGORITHM_HASH__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/categories/is_enum.hpp>
#include<utility/trait/type/miscellaneous/underlying_type.hpp>
#include<utility/trait/config/trait_config.hpp>

#include<utility/algorithm/hash_detail/fnv_hash_1.hpp>
#include<utility/algorithm/hash_detail/fnv_hash_1a.hpp>
#include<utility/algorithm/hash_detail/murmur_hash_2.hpp>

namespace utility
{
  namespace algorithm
  {

    template<typename _T>
    struct hash;

    namespace hash_detail
    {
      template<typename _T,
        bool = ::utility::trait::type::categories::is_enum<_T>::value && __utility_has_underlying_type>
      struct enum_hash
      {
        // static_assert(false, "enum_hash does not support.");
      };
      template<typename _T>
      struct enum_hash<_T, true>
      {
        inline ::utility::size_t operator()(_T __v) const noexcept
        {
          typedef typename
            ::utility::trait::type::miscellaneous::underlying_type<_T>::type
            __under;
          return ::utility::algorithm::hash<__under>{}(static_cast<__under>(__v));
        }
      };

    }

    template<>
    struct hash<bool>
    {
      inline ::utility::size_t operator()(bool __v)const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<char>
    {
      inline ::utility::size_t operator()(char __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<signed char>
    {
      inline ::utility::size_t operator()(signed char __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<unsigned char>
    {
      inline ::utility::size_t operator()(unsigned char __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<signed short>
    {
      inline ::utility::size_t operator()(signed short __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<unsigned short>
    {
      inline ::utility::size_t operator()(unsigned short __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<signed int>
    {
      inline ::utility::size_t operator()(signed int __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<unsigned int>
    {
      inline ::utility::size_t operator()(unsigned int __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<signed long>
    {
      inline ::utility::size_t operator()(signed long __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<unsigned long>
    {
      inline ::utility::size_t operator()(unsigned long __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<signed long long>
    {
      inline ::utility::size_t operator()(signed long long __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<unsigned long long>
    {
      inline ::utility::size_t operator()(unsigned long long __v) const noexcept
      { return static_cast<::utility::size_t>(__v);}
    };
    template<>
    struct hash<float>
    {
      inline ::utility::size_t operator()(float __v) const noexcept
      {
         return __v == 0.0f ? 0 :
          utility::algorithm::hash_detail::fnv_hash_1a<>::__aux(
            &__v, sizeof(__v)
          );
      }
    };
    template<>
    struct hash<double>
    {
      inline ::utility::size_t operator()(double __v) const noexcept
      {
        return __v == 0.0f ? 0 :
          utility::algorithm::hash_detail::fnv_hash_1a<>::__aux(
            &__v, sizeof(__v)
          );
      }
    };
    template<>
    struct hash<long double>
    {
      inline ::utility::size_t operator()(long double __v) const noexcept
      {
        return __v == 0.0f ? 0 :
          utility::algorithm::hash_detail::fnv_hash_1a<>::__aux(
            &__v, sizeof(__v)
          );
      }
    };
    template<typename _T>
    struct hash<_T*>
    {
      inline ::utility::size_t operator()(_T* __v) const noexcept
      { return reinterpret_cast<::utility::size_t>(__v);}
    };
  }
}

#include<utility/trait/config/trait_undef.hpp>

#endif // ! __UTILITY_ALGORITHM_HASH__
