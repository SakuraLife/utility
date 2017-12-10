
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ALIGNED_STORAGE__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ALIGNED_STORAGE__

#include<utility/trait/trait_helper.hpp>
#include<utility/config/utility_config.hpp>

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace miscellaneous
      {
        // aligned_storage
        namespace __aligned_storage_impl
        {
          template<::utility::trait::size_t _Len>
          struct __aligned_storage_helper
          {
            union type
            {
              unsigned char __data[_Len];
              struct alignas(0) { } __align;
            };
          };
        }
        template<::utility::trait::size_t _Len,
          ::utility::trait::size_t _Align = __utility_alignof(
            typename
              __aligned_storage_impl::__aligned_storage_helper<_Len>::type
          )>
        struct aligned_storage
        {
          union type
          {
            unsigned char __data[_Len];
            struct alignas(_Align) { } __align;
          };
        };
      }
    }
  }
}

#endif // __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ALIGNED_STORAGE__
