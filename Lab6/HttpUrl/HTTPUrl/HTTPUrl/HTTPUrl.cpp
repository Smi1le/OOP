#include "stdafx.h"
#include "HTTPUrl.h"
#include <algorithm>


CHttpUrl::CHttpUrl(std::string const &url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	: m_domain(ValidDomainName(domain))
	, m_document(ValidDocumentName(document))
	, m_protocol(protocol)
	, m_port(port)
{

	if (m_port == 80u && m_protocol == Protocol::HTTPS)
	{
		m_port = 443u;
	}
	std::cout << "mport11 = " << m_port << std::endl;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

std::string CHttpUrl::ValidDomainName(std::string const &domain)
{
	if (domain.empty())
	{
		throw std::invalid_argument("Domain name is empty.");
	}
	if (std::find_if(domain.begin(), domain.end(),
		[&](char symbol) {return (symbol == '\'' || isspace(symbol) || symbol == '/t' 
			|| symbol == ':' || symbol == ';' || symbol == '//'); }) != domain.end())
	{
		throw std::invalid_argument("Domain should not enter invalid character");
	}
	return domain;
}

std::string CHttpUrl::ValidDocumentName(std::string const &document)
{
	if (document.empty())
	{
		return "/";
	}
	if (std::find_if(document.begin(), document.end(), [&](char symbol) {return isspace(symbol); }) != document.end())
	{
		throw std::invalid_argument("Document name is failed.");
	}
	if (document[0] != '/')
	{
		return '/' + document;
	}
	return document;
}

void CHttpUrl::ParseUrl(std::string const &url)
{
	try
	{
		std::cout << "m_port11 = " << m_port << std::endl;
		boost::string_ref refUrl(url);
		int begin = 0;
		m_protocol = CheckProtocol(refUrl, begin);
		if (m_protocol == Protocol::HTTPS)
		{
			m_port = 443u;
		}
		else
		{
			m_port = 80u;
		}
		std::cout << "--------------*******************" << std::endl;
		m_domain = ValidDomainName(ParseDomainName(url.substr(begin), begin));
		std::cout << "refUrl = " << refUrl << std::endl;
		std::cout << "GetDomain = " << GetDomain() << std::endl;
		std::cout << "begin = " << begin << std::endl;
		m_document = ValidDocumentName(url.substr(begin));
	}
	catch (std::invalid_argument const &e)
	{
		std::cout << "----------------------------" << std::endl;
		throw CUrlParsingError(e.what());
	}
}

Protocol CHttpUrl::CheckProtocol(boost::string_ref const &url, int &index) const
{
	Protocol protocol = Protocol::HTTP;
	auto pos = url.find("://");
	if (pos != url.size())
	{
		if (url.substr(0, pos) == "https")
		{
			index = pos + 3;
			protocol = Protocol::HTTPS;
		}
		else if (url.substr(0, pos) == "http")
		{
			index = pos + 3;
		}
		else
		{
			std::cout << "8888888888889999999999" << std::endl;
			throw std::invalid_argument("Protocol uncorrect.");
		}
		if (index == url.size())
		{
			throw std::invalid_argument("Invalid url was introduced");
		}
	}
	return protocol;
}

std::string CHttpUrl::ParseDomainName(boost::string_ref const &url, int &index)
{
	for (size_t i = 0; i != url.size(); ++i)
	{
		if (url[i] == '/')
		{
			index += i;
			return std::string(url.substr(0, i));
		}
		if (url[i] == ':')
		{
			m_port = ParsePort(url, i + 1);
			return std::string(url.substr(0, i));
		}
	}
	index += url.size();
	std::cout << "................" << std::endl;
	return std::string(url);
}

unsigned short CHttpUrl::ParsePort(boost::string_ref const &url, size_t index) const
{
	std::string port;
	//int i = 0;
	if (index == url.size() || (index < url.size() && !isdigit(url[index])))
	{
		throw CUrlParsingError("Unknown port in the url address");
	}
	for (; index != url.size(); ++index)
	{
		std::cout << "url[index] = " << url[index] << std::endl;
		if (!isdigit(url[index]))
		{
			break;
		}
		port += url[index];
	}
	return static_cast<unsigned short>(atoi(port.c_str()));
}

int CHttpUrl::GetIndexStartDomainName(boost::string_ref const &url, int index) const
{
	for (size_t i = index; i != url.size(); ++i)
	{
		std::cout << "i = " << i << std::endl;
		std::cout << "url[i] = " << url[i] << std::endl;
		if (isalpha(url[i]) || isspace(url[i]))
		{
			std::cout << "////////////////////////////" << std::endl;
			return i;
		}
	}
	std::cout << "////////////////////////////" << std::endl;
	return url.size();
}

std::string CHttpUrl::ToStringProtocol() const
{
	if (m_protocol == Protocol::HTTP)
	{
		return "http";
	}
	return "https";
}

std::string CHttpUrl::ToStringPort() const
{
	std::cout << "m_port = " << m_port << std::endl;
	if (m_port == 443u || m_port == 80u)
	{
		std::cout << "oooooooooooooooooooo" << std::endl;
		return "";
	}
	return std::to_string(m_port);
}

std::string CHttpUrl::GetURL() const
{
	return ToStringProtocol() + "://" + m_domain + ToStringPort() + m_document;
}