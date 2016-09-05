#include "stdafx.h"
#include "HTTPUrl.h"
#include <algorithm>


CHttpUrl::CHttpUrl(std::string const &url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	: m_domain(ValidateDomainName(domain))
	, m_document(ValidateDocumentName(document))
	, m_protocol(protocol)
	, m_port(port)
{

	if (m_port == 80u && m_protocol == Protocol::HTTPS)
	{
		m_port = 443u;
	}
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

std::string CHttpUrl::ValidateDomainName(std::string const &domain)
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

std::string CHttpUrl::ValidateDocumentName(std::string const &document)
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
		boost::string_ref refUrl(url);
		size_t begin = 0;
		m_protocol = CheckProtocol(refUrl, begin);
		if (m_protocol == Protocol::HTTPS)
		{
			m_port = 443u;
		}
		else
		{
			m_port = 80u;
		}
		m_domain = ValidateDomainName(ParseDomainName(url.substr(begin), begin));
		m_document = ValidateDocumentName(url.substr(begin));
	}
	catch (std::invalid_argument const &e)
	{
		throw CUrlParsingError(e.what());
	}
}

Protocol CHttpUrl::CheckProtocol(boost::string_ref const &url, size_t &index)
{
	Protocol protocol;
	auto pos = url.find("://");
	if (pos != url.size())
	{
		if (url.substr(0, pos) == "https")
		{	
			protocol = Protocol::HTTPS;
		}
		else if (url.substr(0, pos) == "http")
		{
			protocol = Protocol::HTTP;
		}
		else
		{
			throw std::invalid_argument("Protocol uncorrect.");
		}
		if (index == url.size())
		{
			throw std::invalid_argument("Invalid url was introduced");
		}
	}
	index = pos + 3;
	return protocol;
}

std::string CHttpUrl::ParseDomainName(boost::string_ref const &url, size_t &index)
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
	return std::string(url);
}

unsigned short CHttpUrl::ParsePort(boost::string_ref const &url, size_t index)
{
	std::string port;
	if (index == url.size() || (index < url.size() && !isdigit(url[index])))
	{
		throw CUrlParsingError("Unknown port in the url address");
	}
	for (; index != url.size(); ++index)
	{
		if (!isdigit(url[index]))
		{
			break;
		}
		port += url[index];
	}
	return static_cast<unsigned short>(atoi(port.c_str()));
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
	if (m_port == 443u || m_port == 80u)
	{
		return "";
	}
	return std::to_string(m_port);
}

std::string CHttpUrl::GetURL() const
{
	return ToStringProtocol() + "://" + m_domain + ToStringPort() + m_document;
}