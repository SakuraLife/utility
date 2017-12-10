
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_LITERAL_TYPE__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_LITERAL_TYPE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_scalar.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/transform/remove_all_extents.hpp>

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace property
      {
        // is_literal_type
        template<typename _T>
        struct is_literal_type : public
          ::utility::trait::integral_constant<bool,
            ::utility::trait::type::categories::is_scalar<typename
              ::utility::trait::type::transform::remove_all_extents<_T>::type>::value ||
            ::utility::trait::type::categories::is_reference<typename
              ::utility::trait::type::transform::remove_all_extents<_T>::type>::value>
        { };
      }
    }
  }
}

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_LITERAL_TYPE__
