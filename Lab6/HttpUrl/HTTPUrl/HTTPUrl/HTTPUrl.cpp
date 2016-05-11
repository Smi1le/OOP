#include "stdafx.h"
#include "HTTPUrl.h"
#include <algorithm>



CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	: m_domain(ValidDomainName(domain))
	, m_document(ValidDocumentName(document))
	, m_protocol(protocol)
	, m_port(port)
{
	if (m_port == 80 && m_protocol == Protocol::HTTP)
	{
		m_port = 443;
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

std::string CHttpUrl::ValidDomainName(std::string const &domain)
{
	if (domain.empty())
	{
		std::invalid_argument("Domain name is empty.");
	}
	if (std::find_if(domain.begin(), domain.end(),
		[&](char symbol) {return (symbol == '/' || symbol == '\'' || isspace(symbol)); }) != domain.end())
	{
		std::invalid_argument("Domain should not enter a space, slash or backslash");
	}
	return domain;
}

std::string CHttpUrl::ValidDocumentName(std::string const &document)
{
	if (document.empty())
	{
		std::invalid_argument("Document name is empty.");
	}
	if (std::find_if(document.begin(), document.end(), [&](char symbol) {return isspace(symbol)}) != document.end())
	{
		std::invalid_argument("Document name is failed.");
	}
	if (document[0] != '/')
	{
		return '/' + document;
	}
	return document;
}