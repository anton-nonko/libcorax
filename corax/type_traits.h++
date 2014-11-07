///\addtogroup generic
///\{

/**
\defgroup type_traits
\todo Write documentation.
 */

#include <type_traits>
#include <boost/type_traits.hpp>
#include "config.h"

namespace corax {

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::add_const;
using std::add_cv;
using std::add_lvalue_reference;
using std::add_pointer;
#else
using boost::add_const;
using boost::add_cv;
	#if __CORAX_BOOST_AT_LEAST(1,45,0)
using boost::add_lvalue_reference;
	#endif
using boost::add_pointer;
#endif

using boost::add_reference;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::add_rvalue_reference;
using std::add_volatile;
using std::aligned_storage;
using std::alignment_of;
using std::conditional;
using std::common_type;
using std::decay;
using std::enable_if;
using std::extent;
#else
	#if __CORAX_BOOST_AT_LEAST(1,45,0)
using boost::add_rvalue_reference;
	#endif
using boost::add_volatile;
using boost::aligned_storage;
using boost::alignment_of;
using boost::conditional;
	#if __CORAX_BOOST_AT_LEAST(1,45,0)
using boost::common_type;
	#endif
using boost::decay;
using boost::enable_if;
using boost::extent;
#endif

using boost::floating_point_promotion;
using boost::function_traits;
using boost::has_bit_and;
using boost::has_bit_and_assign;
using boost::has_bit_or;
using boost::has_bit_or_assign;
using boost::has_bit_xor;
using boost::has_bit_xor_assign;
using boost::has_complement;
using boost::has_dereference;
using boost::has_divides;
using boost::has_divides_assign;
using boost::has_equal_to;
using boost::has_greater;
using boost::has_greater_equal;
using boost::has_left_shift;
using boost::has_left_shift_assign;
using boost::has_less;
using boost::has_less_equal;
using boost::has_logical_and;
using boost::has_logical_not;
using boost::has_logical_or;
using boost::has_minus;
using boost::has_minus_assign;
using boost::has_modulus;
using boost::has_modulus_assign;
using boost::has_multiplies;
using boost::has_multiplies_assign;
using boost::has_negate;
using boost::has_new_operator;
using boost::has_not_equal_to;
using boost::has_nothrow_assign;
using boost::has_nothrow_constructor;
using boost::has_nothrow_copy;
using boost::has_nothrow_copy_constructor;
using boost::has_nothrow_default_constructor;
using boost::has_plus;
using boost::has_plus_assign;
using boost::has_post_decrement;
using boost::has_post_increment;
using boost::has_pre_decrement;
using boost::has_pre_increment;
using boost::has_right_shift;
using boost::has_right_shift_assign;
using boost::has_trivial_assign;
using boost::has_trivial_constructor;
using boost::has_trivial_copy;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::has_trivial_copy_constructor;
using std::has_trivial_default_constructor;
#else
using boost::has_trivial_copy_constructor;
using boost::has_trivial_default_constructor;
#endif

using boost::has_trivial_destructor;
using boost::has_trivial_move_assign;
using boost::has_trivial_move_constructor;
using boost::has_unary_minus;
using boost::has_unary_plus;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::has_virtual_destructor;
using std::integral_constant;
#else
using boost::has_virtual_destructor;
using boost::integral_constant;
#endif

using boost::integral_promotion;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::is_abstract;
using std::is_arithmetic;
using std::is_array;
using std::is_base_of;
using std::is_class;
#else
using boost::is_abstract;
using boost::is_arithmetic;
using boost::is_array;
using boost::is_base_of;
using boost::is_class;
#endif

using boost::is_complex;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::is_compound;
using std::is_const;
using std::is_convertible;
using std::is_copy_assignable;
using std::is_copy_constructible;
using std::is_empty;
using std::is_enum;
#else
using boost::is_compound;
using boost::is_const;
using boost::is_convertible;
	#if __CORAX_BOOST_AT_LEAST(1,57,0)
using boost::is_copy_assignable;
	#endif
	#if __CORAX_BOOST_AT_LEAST(1,55,0)
using boost::is_copy_constructible;
	#endif
using boost::is_empty;
using boost::is_enum;
#endif

#if __CORAX_BOOST_AT_LEAST(1,57,0)
using boost::is_final;
#endif

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::is_floating_point;
using std::is_function;
using std::is_fundamental;
using std::is_integral;
using std::is_lvalue_reference;
using std::is_member_function_pointer;
using std::is_member_object_pointer;
using std::is_member_pointer;
using std::is_nothrow_move_assignable;
using std::is_nothrow_move_constructible;
using std::is_object;
using std::is_pod;
using std::is_pointer;
using std::is_polymorphic;
using std::is_reference;
using std::is_rvalue_reference;
using std::is_same;
using std::is_scalar;
using std::is_signed;
#else
using boost::is_floating_point;
using boost::is_function;
using boost::is_fundamental;
using boost::is_integral;
	#if __CORAX_BOOST_AT_LEAST(1,45,0)
using boost::is_lvalue_reference;
	#endif
using boost::is_member_function_pointer;
using boost::is_member_object_pointer;
using boost::is_member_pointer;
using boost::is_nothrow_move_assignable;
using boost::is_nothrow_move_constructible;
using boost::is_object;
using boost::is_pod;
using boost::is_pointer;
using boost::is_polymorphic;
using boost::is_reference;
	#if __CORAX_BOOST_AT_LEAST(1,45,0)
using boost::is_rvalue_reference;
	#endif
using boost::is_same;
using boost::is_scalar;
using boost::is_signed;
#endif

using boost::is_stateless;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::is_union;
using std::is_unsigned;
#else
using boost::is_union;
using boost::is_unsigned;
#endif

using boost::is_virtual_base_of;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::is_void;
using std::is_volatile;
using std::make_signed;
using std::make_unsigned;
#else
using boost::is_void;
using boost::is_volatile;
using boost::make_signed;
using boost::make_unsigned;
#endif

using boost::promote;

#if __CORAX_GCC_AT_LEAST(4,8,0)
using std::rank;
using std::remove_all_extents;
using std::remove_const;
using std::remove_cv;
using std::remove_extent;
using std::remove_pointer;
using std::remove_reference;
using std::remove_volatile;
#endif

using boost::type_with_alignment;

}; //corax

///\} //type_traits
///\} //generic
