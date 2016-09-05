#include "stdafx.h"
#include "../MyStack/MyStack.h"

BOOST_AUTO_TEST_SUITE(MyStack) 

	BOOST_AUTO_TEST_CASE(initialize_the_stack_without_parameters)
	{
		CMyStack<std::string> stringStack;
		BOOST_CHECK(stringStack.GetSize() == 0);
		BOOST_REQUIRE_THROW(stringStack.Peek(), std::exception);
		BOOST_CHECK(stringStack.IsEmpty());
		BOOST_REQUIRE_THROW(stringStack.Pop(), std::exception);
	}

	BOOST_AUTO_TEST_CASE(initialize_the_stack_handing_to_another_stack)
	{
		CMyStack<std::string> stringStack;

		for (int i = 0; i != 3; ++i)
		{
			BOOST_CHECK_NO_THROW(stringStack.Push(std::to_string(i * 3)));
		}

		CMyStack<std::string> copyStringStack(stringStack);
		BOOST_CHECK(!copyStringStack.IsEmpty());
		BOOST_CHECK(!stringStack.IsEmpty());
		BOOST_CHECK(copyStringStack.GetSize() == 3);
		BOOST_CHECK(stringStack.GetSize() == 3);
		BOOST_REQUIRE_NO_THROW(copyStringStack.Peek());
		BOOST_REQUIRE_NO_THROW(stringStack.Peek());
		BOOST_CHECK_EQUAL(copyStringStack.Peek(), stringStack.Peek());
	}

	BOOST_AUTO_TEST_CASE(initialization_of_the_stack_by_means_of_move_construction)
	{
		CMyStack<std::string> stringStack;
		for (int i = 0; i != 3; ++i)
		{
			BOOST_CHECK_NO_THROW(stringStack.Push(std::to_string(i * 3)));
		}

		auto topStringStack = stringStack.Peek();

		CMyStack<std::string> copyStringStack(std::move(stringStack));
		BOOST_CHECK(!copyStringStack.IsEmpty());
		BOOST_CHECK(stringStack.IsEmpty());
		BOOST_CHECK(copyStringStack.GetSize() == 3);
		BOOST_CHECK(stringStack.GetSize() == 0);
		BOOST_REQUIRE_NO_THROW(copyStringStack.Peek());
		BOOST_CHECK_THROW(stringStack.Peek(), std::exception);
		BOOST_CHECK_EQUAL(copyStringStack.Peek(), topStringStack);
	}

	
	struct that_works_correctly_stack_all_methods
	{
		CMyStack<int> stack;
	};

	BOOST_FIXTURE_TEST_SUITE(stack_methods, that_works_correctly_stack_all_methods)

		BOOST_AUTO_TEST_CASE(method_push_and_check_top_stack)
		{
			BOOST_REQUIRE_THROW(stack.Peek(), std::exception);
			BOOST_CHECK_NO_THROW(stack.Push(5));
			BOOST_CHECK(stack.Peek() == 5);
			BOOST_CHECK_NO_THROW(stack.Push(90));
			BOOST_CHECK(stack.Peek() == 90);
			BOOST_CHECK_NO_THROW(stack.Push(495845));
			BOOST_CHECK(stack.Peek() == 495845);
			BOOST_CHECK(!stack.IsEmpty());
			BOOST_CHECK_EQUAL(stack.GetSize(), 3);
		}

	BOOST_AUTO_TEST_SUITE_END()

	struct that_works_correctly_stack_another_methods
	{
		that_works_correctly_stack_another_methods()
		{
			BOOST_REQUIRE_NO_THROW(stack.Push("This is a long string"));
			BOOST_REQUIRE_NO_THROW(stack.Push("This is a medium string"));
			BOOST_REQUIRE_NO_THROW(stack.Push("This is M.D. House"));
		}
		CMyStack<std::string> stack;

	};

	BOOST_FIXTURE_TEST_SUITE(another_methods_in_stack, that_works_correctly_stack_another_methods)
	
		BOOST_AUTO_TEST_CASE(pop_method_with_check_top_stack)
		{
			
			BOOST_CHECK_EQUAL(stack.Peek(), "This is M.D. House"); 
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK_EQUAL(stack.Peek(), "This is a medium string"); 
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_CHECK_EQUAL(stack.Peek(), "This is a long string");
			BOOST_CHECK_NO_THROW(stack.Pop());
			BOOST_REQUIRE_THROW(stack.Peek(), std::exception);
			BOOST_REQUIRE_THROW(stack.Pop(), std::exception);
			BOOST_CHECK(stack.IsEmpty());
		}

	BOOST_AUTO_TEST_CASE(clear_method)
	{
		BOOST_CHECK_EQUAL(stack.GetSize(), 3);
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_REQUIRE_NO_THROW(stack.Clear());
		BOOST_CHECK(stack.IsEmpty());
		BOOST_CHECK_EQUAL(stack.GetSize(), 0);
	}

	BOOST_AUTO_TEST_CASE(assignment_operator)
	{
		CMyStack<std::string> secondStack;
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_REQUIRE_NO_THROW(secondStack = stack);
		BOOST_CHECK(!secondStack.IsEmpty());
		BOOST_CHECK_EQUAL(secondStack.GetSize(), stack.GetSize());
		BOOST_CHECK_EQUAL(secondStack.Peek(), stack.Peek());
		
		BOOST_REQUIRE_NO_THROW(stack.Pop());
		BOOST_REQUIRE_NO_THROW(secondStack.Pop());
		BOOST_CHECK(!secondStack.IsEmpty());
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_CHECK_EQUAL(secondStack.GetSize(), stack.GetSize());
		BOOST_CHECK_EQUAL(secondStack.Peek(), stack.Peek());
		
		BOOST_REQUIRE_NO_THROW(stack.Pop());
		BOOST_REQUIRE_NO_THROW(secondStack.Pop());
		BOOST_CHECK(!secondStack.IsEmpty());
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_CHECK_EQUAL(secondStack.GetSize(), stack.GetSize());
		BOOST_CHECK_EQUAL(secondStack.Peek(), stack.Peek());
	}

	BOOST_AUTO_TEST_CASE(moves_the_assignment_operator)
	{
		CMyStack<std::string> secondStack;
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_REQUIRE_NO_THROW(secondStack = std::move(stack));
		BOOST_CHECK(!secondStack.IsEmpty());
		BOOST_CHECK(stack.IsEmpty());
		BOOST_CHECK_EQUAL(secondStack.GetSize(), 3);
		BOOST_CHECK_EQUAL(stack.GetSize(), 0);
		BOOST_CHECK_EQUAL(secondStack.Peek(), "This is M.D. House");
		BOOST_REQUIRE_THROW(stack.Peek(), std::exception);
		BOOST_REQUIRE_THROW(stack.Pop(), std::exception);
	}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()