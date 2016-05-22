#include "stdafx.h"
#include "../MyStack/MyStack.h"

BOOST_AUTO_TEST_SUITE(MyStack) 

	struct that_works_correctly_stack_methods
	{
		CMyStack<int> stack;
	};

	BOOST_FIXTURE_TEST_SUITE(stack_methods, that_works_correctly_stack_methods)

		BOOST_AUTO_TEST_CASE(method_push_and_method_peek)
		{
			BOOST_CHECK_NO_THROW(stack.Push(5));
			BOOST_CHECK(stack.Peek() == 5);
			BOOST_CHECK_NO_THROW(stack.Push(90));
			BOOST_CHECK(stack.Peek() == 90);
			BOOST_CHECK_NO_THROW(stack.Push(495845));
			BOOST_CHECK(stack.Peek() == 495845);
			BOOST_CHECK_NO_THROW(stack.Push(234));
			BOOST_CHECK(stack.Peek() == 234);
			BOOST_CHECK_NO_THROW(stack.Push(-65));
			BOOST_CHECK(stack.Peek() == -65);
		}

		BOOST_AUTO_TEST_CASE(method_pop_and_method_peek)
		{
			BOOST_CHECK_NO_THROW(stack.Push(5));
			BOOST_CHECK_NO_THROW(stack.Push(90));
			BOOST_CHECK_NO_THROW(stack.Push(495845));
			BOOST_CHECK_NO_THROW(stack.Push(234));
			BOOST_CHECK_NO_THROW(stack.Push(-65));
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(stack.Peek() == 234);
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(stack.Peek() == 495845);
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(stack.Peek() == 90);
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(stack.Peek() == 5);
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK_THROW(stack.Peek(), std::out_of_range);
		}

		BOOST_AUTO_TEST_CASE(method_IsEmpty)
		{
			BOOST_CHECK_NO_THROW(stack.Push(5));
			BOOST_CHECK_NO_THROW(stack.Push(90));
			BOOST_CHECK_NO_THROW(stack.Push(495845));
			BOOST_CHECK_NO_THROW(stack.Push(234));
			BOOST_CHECK_NO_THROW(stack.Push(-65));
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(!stack.IsEmpty());
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(!stack.IsEmpty());
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(!stack.IsEmpty());
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(!stack.IsEmpty());
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK(stack.IsEmpty());
		}

		BOOST_AUTO_TEST_CASE(method_Clear)
		{
			BOOST_CHECK_NO_THROW(stack.Push(5));
			BOOST_CHECK_NO_THROW(stack.Push(90));
			BOOST_CHECK_NO_THROW(stack.Push(495845));
			BOOST_CHECK_NO_THROW(stack.Push(234));
			BOOST_CHECK_NO_THROW(stack.Push(-65));
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK_NO_THROW(stack.Clear());
			BOOST_CHECK(stack.IsEmpty());
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()