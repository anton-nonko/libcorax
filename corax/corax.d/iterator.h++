/**
\addtogroup fundamentals \{
\defgroup iterators
\{
*/

#pragma once

#include <boost/iterator/iterator_facade.hpp>

namespace corax {

using boost::iterator_facade;
using boost::iterator_core_access;

using boost::no_traversal_tag;
using boost::incrementable_traversal_tag;
using boost::single_pass_traversal_tag;
using boost::forward_traversal_tag;
using boost::bidirectional_traversal_tag;
using boost::random_access_traversal_tag;

}; //corax

///\} //iterators
///\} //fundamentals
