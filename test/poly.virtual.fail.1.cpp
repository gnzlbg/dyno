// Copyright Louis Dionne 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include "testing.hpp"

#include <te/concept.hpp>
#include <te/concept_map.hpp>
#include <te/poly.hpp>
using namespace te::literals;


struct Concept : decltype(te::requires(
  "f"_s = te::function<int (te::T*)>
)) { };

struct Foo { };

template <>
auto const te::concept_map<Concept, Foo> = te::make_concept_map(
  "f"_s = [](Foo*) { return 111; }
);

int main() {
  Foo foo;
  te::poly<Concept> poly{foo};
  // MESSAGE[te::poly::virtual_: Passing a non-poly object as an argument]
  TE_CHECK(poly.virtual_("f"_s)(static_cast<void*>(&poly)) == 111);
}
