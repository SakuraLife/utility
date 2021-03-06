
#ifndef __UTILITY_MEMORY_UNINITIALIZED_COPY_N__
#define __UTILITY_MEMORY_UNINITIALIZED_COPY_N__

#include<utility/config/utility_config.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/trait/type/categories/is_arithmetic.hpp>
#include<utility/trait/type/categories/is_pointer.hpp>
#include<utility/trait/type/property/is_pod.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/sstd/new.hpp>
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace memory
  {
    namespace detail
    {
      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      _ForwardIterator
      __uninitialized_copy_n(_InputIterator __first,
        _Size __size, _ForwardIterator __result,
        trait::false_type
      )
      {
        typedef typename
          iterator::iterator_traits<_ForwardIterator>::value_type
          __value_type;
#ifdef __UTILITY_USE_EXCEPTION
        _ForwardIterator __epos = __result;
#endif // ! __UTILITY_USE_EXCEPTION
        __UTILITY_TRY_BEGIN
          for(; __size > 0; (void)++__first, ++__result, --__size)
          {
            ::new (static_cast<void*>(memory::addressof(*__result)))
            __value_type(*__first);
          }
        __UTILITY_TRY_END
        __UTILITY_CATCH(...)
        __UTILITY_CATCH_UNWIND(
          for(; __epos != __result; ++__epos)
          { __epos->~__value_type();}
        )
        return __result;
      }
      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      _ForwardIterator
      __uninitialized_copy_n(_InputIterator __first,
        _Size __size, _ForwardIterator __result,
        trait::true_type
      )
      {
        typedef typename
          iterator::iterator_traits<_ForwardIterator>::value_type
          __value_type;
        sstd::memmove(
          __result, __first, __size*sizeof(__value_type));
        return __result + __size;
      }
    }

    /*!
    * \brief Copy block of memory
    *
    * Constructs copies of the \a __size first elements of the array
    * pointed by \a __first into a range beginning at \a __result
    * and returns an iterator to the last element in the destination range.<br/>
    * \b uninitialized_copy constructs the objects in-place,
    * instead of just copying them. This allows to obtain fully constructed
    * copies of the elements into a range of uninitialized memory.
    *
    * \param __first  Forward iterator to the initial position in
    *         an uninitialized sequence of at least \a __size elements.
    * \param __size   Number of elements to copy.
    * \param __result Output iterator to the initial position
    *         in the uninitialized destination sequence.
    *         This shall not point to any element in
    *         the range [\a __first, \a __first+\a __size).
    * \return An iterator to the last element of the destination sequence
    *         where elements have been copied.
    * \attention If an exception is thrown during the initialization,
    *         the function has no effects.
    * \note   If the \a _ForwardIterator and \a _InputIterator are both pointer
    *         the memmove is used to speed up copying.
    * \see memory::uninitialized_copy
    */
    template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    _ForwardIterator
    uninitialized_copy_n(_InputIterator __first,
      _Size __size, _ForwardIterator __result)
    {
      typedef typename
        iterator::iterator_traits<_ForwardIterator>::value_type
        __value_type;
      typedef
        trait::integral_constant<bool,
          trait::type::categories::is_pointer<_InputIterator>::value &&
          trait::type::categories::is_pointer<_ForwardIterator>::value &&
          (trait::type::categories::is_arithmetic<__value_type>::value ||
           trait::type::categories::is_pointer<__value_type>::value ||
           trait::type::property::is_pod<__value_type>::value)>
        __identify;
      return detail::__uninitialized_copy_n(__first, __size, __result, __identify());
    }
  }
}

#endif // ! __UTILITY_MEMORY_UNINITIALIZED_COPY_N__
