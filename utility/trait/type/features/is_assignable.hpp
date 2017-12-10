
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_ASSIGNABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_ASSIGNABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/categories/is_void.hpp>

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace features
      {
        // is_assignable
        namespace __is_assignable_impl
        {
          using __two = ::utility::trait::__impl_helper::__twochar;
          template<typename _T, typename _F>
          struct __is_assignable_test
          {
            private:
              template<typename _To, typename _From>
              static
              decltype((::utility::trait::type::special::declval<_To>() = ::utility::trait::type::special::declval<_From>()),char('\0'))
              __test(int);
              template<typename, typename>
              static __two __test(...);
            public:
              constexpr static bool value = sizeof(__test<_T, _F>(0)) == sizeof(char);
          };

          template<typename _To, typename _From, bool =
            ::utility::trait::type::categories::is_void<_To>::value ||
            ::utility::trait::type::categories::is_void<_From>::value>
          struct __is_assignable_helper : public ::utility::trait::false_type
          { };

          template<typename _To, typename _From>
          struct __is_assignable_helper<_To, _From, false> :
            public ::utility::trait::integral_constant<bool,
              __is_assignable_test<_To, _From>::value>
          { };
        }
        template<typename _T, typename _U>
        struct is_assignable : public
          __is_assignable_impl::__is_assignable_helper<_T, _U>
        { };
      }
    }
  }
}

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_ASSIGNABLE__
