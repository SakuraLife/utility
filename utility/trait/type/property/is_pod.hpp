
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_POD__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_POD__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_pod

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace property
      {
        // is_pod
        template<typename _T>
        struct is_pod : public
          utility::trait::integral_constant<bool, __utility_is_pod(_T)>
        { };

      }
    }
  }
}

#else // __utility_has_is_pod

#include<utility/trait/type/features/is_trivially_default_constructible.hpp>
#include<utility/trait/type/features/is_trivially_copy_constructible.hpp>
#include<utility/trait/type/features/is_trivially_copy_assignable.hpp>
#include<utility/trait/type/features/is_trivially_destructible.hpp>

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace property
      {
        // is_pod
        template<typename _T>
        struct is_pod : public
          utility::trait::integral_constant<bool,
            utility::trait::type::features::is_trivially_default_constructible<_T>::value &&
            utility::trait::type::features::is_trivially_copy_constructible<_T>::value &&
            utility::trait::type::features::is_trivially_copy_assignable<_T>::value &&
            utility::trait::type::features::is_trivially_destructible<_T>::value>
        { };

      }
    }
  }
}

#endif // __utility_has_is_pod

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace property
      {
        template<typename _T>
        struct is_pod<_T*> : public utility::trait::true_type
        { };
        template<typename _T>
        struct is_pod<_T* const> : public utility::trait::true_type
        { };
        template<typename _T>
        struct is_pod<_T* volatile> : public utility::trait::true_type
        { };
        template<typename _T>
        struct is_pod<_T* const volatile> : public utility::trait::true_type
        { };

        template<>
        struct is_pod<char> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<signed char> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<unsigned char> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<signed short> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<unsigned short> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<signed int> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<unsigned int> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<signed long> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<unsigned long> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<signed long long> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<unsigned long long> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<float> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<double> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<long double> : public utility::trait::true_type
        { };

        template<>
        struct is_pod<wchar_t> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<char16_t> : public utility::trait::true_type
        { };
        template<>
        struct is_pod<char32_t> : public utility::trait::true_type
        { };
      }
    }
  }
}

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_POD__
