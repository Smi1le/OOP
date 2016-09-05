#pragma once
#include "UrlParsingError.h"
#include <boost/utility/string_ref.hpp>
#include <iostream>


class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);

	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP,
		unsigned short port = 80u);

	std::string GetURL()const;
	std::string GetDomain()const;
	std::string GetDocument()const;
	Protocol GetProtocol()const;
	unsigned short GetPort()const;

	
private:
	static std::string ValidateDomainName(std::string const &domain);
	static std::string ValidateDocumentName(std::string const &domain);
	void ParseUrl(std::string const &url);
	static Protocol CheckProtocol(boost::string_ref const &protocol, size_t &index);
	std::string ParseDomainName(boost::string_ref const &url, size_t &index);
	static unsigned short ParsePort(boost::string_ref const &url, size_t index);
	std::string ToStringProtocol() const;
	std::string ToStringPort() const;


	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
