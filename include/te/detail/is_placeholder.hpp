// Copyright Louis Dionne 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef TE_DETAIL_IS_PLACEHOLDER_HPP
#define TE_DETAIL_IS_PLACEHOLDER_HPP

#include <te/detail/dsl.hpp>

#include <type_traits>


namespace te { namespace detail {

// Metafunction returning whether a type is a possibly cv/ref-qualified
// placeholder, or a pointer to one.
template <typename T>
struct is_placeholder : std::false_type { };

template <> struct is_placeholder<te::T&> : std::true_type { };
template <> struct is_placeholder<te::T&&> : std::true_type { };
template <> struct is_placeholder<te::T*> : std::true_type { };

template <> struct is_placeholder<te::T const&> : std::true_type { };
template <> struct is_placeholder<te::T const&&> : std::true_type { };
template <> struct is_placeholder<te::T const*> : std::true_type { };

}} // end namespace te::detail

#endif // TE_DETAIL_IS_PLACEHOLDER_HPP
