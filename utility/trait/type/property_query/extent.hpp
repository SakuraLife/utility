
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_EXTENT__
#define __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_EXTENT__

#include<utility/trait/trait_helper.hpp>

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace property_query
      {
        // extent
        template<typename _T, unsigned int _I = 0>
        struct extent :
          public ::utility::trait::integral_constant<::utility::trait::size_t, 0>
        { };
        template<typename _T, unsigned int _I>
        struct extent<_T[], _I> :
          public ::utility::trait::integral_constant<
            ::utility::trait::size_t, extent<_T, _I-1>::value>
        { };
        template<typename _T>
        struct extent<_T[], 0> :
          public ::utility::trait::integral_constant<::utility::trait::size_t, 0>
        { };
        template<typename _T, ::utility::trait::size_t _size>
        struct extent<_T[_size], 0> :
          public ::utility::trait::integral_constant<
            ::utility::trait::size_t, _size>
        { };
        template<typename _T, ::utility::trait::size_t _size,
                unsigned int _I>
        struct extent<_T[_size], _I> :
          public ::utility::trait::integral_constant<
            ::utility::trait::size_t, extent<_T, _I-1>::value>
        { };

      }
    }
  }
}

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_EXTENT__