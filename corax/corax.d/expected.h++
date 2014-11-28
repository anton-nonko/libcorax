#pragma once

#include <functional>

namespace corax {

template<class>
class expected;

template<class>
class basic_expected;

//------------------------------------------------------------------------------
template<class T>
class expected_traits {
	friend class basic_expected<T>;

	typedef T                               value_type;
	typedef T                               storage;
	typedef T*                              pointer;
	typedef T&                              reference;
}; //expected_traits

template<class T>
class expected_traits<T&> {
	friend class basic_expected<T&>;

	typedef T                               value_type;
	typedef std::reference_wrapper<T>       storage;
	typedef T*                              pointer;
	typedef T&                              reference;
}; //expected_traits<T&>

template<class T>
class expected_traits<const T&> {
	friend class basic_expected<const T&>;

	typedef T                               value_type;
	typedef std::reference_wrapper<const T> storage;
	typedef const T*                        pointer;
	typedef const T&                        reference;
}; //expected_traits<const T&>

//------------------------------------------------------------------------------
template<class T>
class basic_expected {
	friend class expected<T>;

	typedef expected_traits<T> traits;
	typedef typename traits::value_type value_type;
	typedef typename traits::storage    storage;
	typedef typename traits::pointer    pointer;
	typedef typename traits::reference  reference;

	inline basic_expected();
	inline basic_expected(const value_type& value);
	inline basic_expected(value_type& value);
	inline basic_expected(value_type&& value);

	template<class... AA>
	inline explicit basic_expected(AA&&... arguments);

	inline basic_expected(const basic_expected& other);
	inline basic_expected(basic_expected&& other);

	inline ~basic_expected();

	inline void swap(basic_expected& other);

public:
	/**
	Create an invalid object containing exception of type `E`.
	*/
	template<class E>
	inline static expected<T> from_exception(const E& exception);

	/**
	Create an invalid object containing `std::exception_ptr`.
	*/
	inline static expected<T> from_exception(std::exception_ptr exception);

	/**
	Create an invalid object containing currently catched exception.

	Should be called from `catch` block. Is equivalent of
	#from_exception (std::current_exception());
	*/
	inline static expected<T> from_exception();

	/**
	Make `expected` containing a value returned by function or an exception
	if thrown.
	*/
	template<class F, class... AA>
	inline static expected<T> from_code(F function, AA&&... arguments);

	/**
	Returns `true` if object contains a valid value, `false` otherwise.
	*/
	inline operator bool() const;

	/**
	Returns `true` if object contains exception of type `E`.

	If object contains valid value (i.e. \link operator bool() const \endlink returns `true`
	) behaviour is undefined.
	*/
	template<class E>
	inline bool exception_is() const;

private:
	inline reference get();
	inline const reference get() const;

public:
	/**
	Returns reference to holded value.
	\throw <runtime_defined> Exception holded if invalid.
	*/
	inline reference operator * ();

	/**
	Returns constant reference to holded value.
	\throw <runtime_defined> Exception holded if invalid.
	*/
	inline const reference operator * () const;

	/**
	Returns pointer to holded value.
	\throw <runtime_defined> Exception holded if invalid.
	*/
	inline pointer operator -> ();

	/**
	Returns constant pointer to holded value.
	\throw <runtime_defined> Exception holded if invalid.
	*/
	inline const pointer operator -> () const;

private:
	bool                 m_valid;
	union {
		storage            m_storage;
		std::exception_ptr m_exception;
	};
}; //basic_expected

}; //corax
