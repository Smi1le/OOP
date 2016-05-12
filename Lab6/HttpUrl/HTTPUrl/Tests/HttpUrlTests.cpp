#include "stdafx.h"
#include "../HTTPUrl/HTTPUrl.h"

BOOST_AUTO_TEST_SUITE(Tests_for_parse_url)

	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_string)

		BOOST_AUTO_TEST_CASE(url_can_not_be_initialized_with_the_wrong_protocol)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("ftp://vk.com/animate.html"), CUrlParsingError);
		}
		
		BOOST_AUTO_TEST_CASE(can_not_initialize_if_the_url_after_the_port_is_not_worth_the_correct_delimiter)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("http:vk.com/animate.html"), CUrlParsingError);
		}

		BOOST_AUTO_TEST_CASE(if_the_correct_protocol_written_properly)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("htt p://vk.com/animate.html"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl url("htt.p://vk.com/animate.html"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl url("htt-s://vk.com/animate.html"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl url("htt/p://vk.com/animate.html"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl url("htt?p://vk.com/animate.html"), CUrlParsingError);
		}

		BOOST_AUTO_TEST_SUITE(if_the_misspelled_domain_name)
			BOOST_AUTO_TEST_CASE(if_in_domain_name_there_is_a_gap)
			{
				BOOST_REQUIRE_THROW(CHttpUrl url("http://vk .com/animate.html"), CUrlParsingError);
			}

			BOOST_AUTO_TEST_CASE(if_the_domain_name_of_the_place_are_the_gaps)
			{
				BOOST_REQUIRE_THROW(CHttpUrl url("http://          /animate.html"), CUrlParsingError);
			}
			
			BOOST_AUTO_TEST_CASE(if_in_domain_name_is_not)
			{

				BOOST_REQUIRE_THROW(CHttpUrl url("https:///animate.html"), CUrlParsingError);
			}

			BOOST_AUTO_TEST_CASE(if_domain_name_is_present_tab)
			{
				BOOST_REQUIRE_THROW(CHttpUrl url("https://vk	.com/animate.html"), CUrlParsingError);
			}

			
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_CASE(it_is_possible_to_create_a_url_without_throwing_exceptions)
		{
			BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://vk.com5454"));
			BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://vk.com/kjhkh"));
			BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://vk.com/animate.html"));
		}

		BOOST_AUTO_TEST_CASE(if_document_is_empty_then_get_doc_returns_empty_doc_with_slash_ch)
		{
			CHttpUrl firstUrl("https://vk.com/");
			BOOST_CHECK_EQUAL(firstUrl.GetDocument(), "/");

			CHttpUrl secondUrl("https://vk.com");
			BOOST_CHECK_EQUAL(secondUrl.GetDocument(), "/");
		}

		BOOST_AUTO_TEST_CASE(if_url_contains_non_empty_document_get_doc_returns_him)
		{
			CHttpUrl url("https://vk.com/animate.html");
			BOOST_CHECK_EQUAL(url.GetDocument(), "/animate.html");
		}

		BOOST_AUTO_TEST_CASE(if_url_contains_port_then_port_will_be_different_from_standart)
		{
			CHttpUrl url("http://vk.com:14/animate.html");
			BOOST_CHECK_EQUAL(url.GetPort(), 14u);
		}

		BOOST_AUTO_TEST_CASE(port_may_be_final_element)
		{
			CHttpUrl url("http://vk.com:14");
			BOOST_CHECK_EQUAL(url.GetPort(), 14u);
		}

		BOOST_AUTO_TEST_CASE(if_there_is_a_colon_and_no_port_class_throw_excpt)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("http://vk.com:"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl url("http://vk.com:/animate.html"), CUrlParsingError);
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_components)

		BOOST_AUTO_TEST_CASE(can_not_pass_an_invalid_domain_name)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("", "animate"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(can_not_pass_an_invalid_document)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("vk.com", "	"), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(can_not_pass_an_domain_name_with_scheme_or_slash)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("https://vk.vk.com", "animate"), std::invalid_argument);

		}

		BOOST_AUTO_TEST_CASE(if_document_does_not_begin_with_slash_it_will_be_added)
		{
			CHttpUrl url1("vk.com", "");
			BOOST_CHECK_EQUAL(url1.GetDocument(), "/");

			CHttpUrl url2("vk.com", "animate.html");
			BOOST_CHECK_EQUAL(url2.GetDocument(), "/animate.html");
		}

		BOOST_AUTO_TEST_CASE(default_protocol_is_http_and_default_port_is_80)
		{
			CHttpUrl url("vk.com", "animate.html");
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTP);
			BOOST_CHECK_EQUAL(url.GetPort(), 80u);
		}

		BOOST_AUTO_TEST_CASE(can_explicitly_specify_the_protocol)
		{
			CHttpUrl url("vk.com", "animate.html", Protocol::HTTPS);
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK_EQUAL(url.GetPort(), 443u);
		}

		BOOST_AUTO_TEST_CASE(can_explicitly_specify_the_port_of_fourth_parameter)
		{
			CHttpUrl url("vk.com", "animate.html", Protocol::HTTPS, 05);
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
			BOOST_CHECK_EQUAL(url.GetPort(), 5u);
		}

	BOOST_AUTO_TEST_SUITE_END()

		struct initialize_url_
	{
		initialize_url_()
			: urlStr("https://vk.com/animate.html")
			, url(urlStr)
		{};

		std::string urlStr;
		CHttpUrl url;
	};

	BOOST_FIXTURE_TEST_SUITE(before_initialized_url, initialize_url_)

		BOOST_AUTO_TEST_CASE(can_get_the_protocol)
		{
			BOOST_CHECK(url.GetProtocol() == Protocol::HTTPS);
		}

		BOOST_AUTO_TEST_CASE(as_our_protocol_has_equal_that_https_then_port_is_equal_443)
		{
			BOOST_CHECK_EQUAL(url.GetPort(), 443u);
		}

		BOOST_AUTO_TEST_CASE(can_get_the_domain_name)
		{
			BOOST_CHECK_EQUAL(url.GetDomain(), "vk.com");
		}

		BOOST_AUTO_TEST_CASE(can_get_the_document_with_slash_in_begin)
		{
			BOOST_CHECK_EQUAL(url.GetDocument(), "/animate.html");
		}

		BOOST_AUTO_TEST_CASE(can_get_the_url)
		{
			BOOST_CHECK_EQUAL(url.GetURL(), urlStr);
		}

	BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()