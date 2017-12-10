
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_DECAY__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_DECAY__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_array.hpp>
#include<utility/trait/type/categories/is_function.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>
#include<utility/trait/type/transform/remove_extent.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/transform/add_pointer.hpp>
#include<utility/trait/type/miscellaneous/conditional.hpp>

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace transform
      {
        // decay
        template<typename _T>
        struct decay
        {
          private:
            typedef typename
              ::utility::trait::type::transform::remove_reference
              < _T>::type _type;
          public:
            typedef typename
              ::utility::trait::type::miscellaneous::conditional
              <
                ::utility::trait::type::categories::is_array<_type>::value,
                typename ::utility::trait::type::transform::remove_extent<_type>::type*,
                typename
                ::utility::trait::type::miscellaneous::conditional
                <
                  ::utility::trait::type::categories::is_function<_type>::value,
                  typename
                  ::utility::trait::type::transform::add_pointer<_type>::type,
                  typename
                  ::utility::trait::type::transform::remove_cv<_type>::type
                >::type
              >::type type;
        };

      }
    }
  }
}

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_DECAY__
