#pragma once
#include "UrlParsingError.h"
#include <boost/utility/string_ref.hpp>
#include <iostream>


class CHttpUrl
{
public:
	// ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
	// ���������� ���������� CUrlParsingError, ���������� ��������� �������� ������
	CHttpUrl(std::string const& url);

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	std::invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP,
		unsigned short port = 80u);

	// ���������� ��������� ������������� URL-�. ����, ���������� ����������� ���
	// ���������� ��������� (80 ��� http � 443 ��� https) � URL �� ������ ����������
	std::string GetURL()const;

	// ���������� �������� ���
	std::string GetDomain()const;

	/*
	���������� ��� ���������. �������:
	/
	/index.html
	/images/photo.jpg
	*/
	std::string GetDocument()const;
	Protocol GetProtocol()const;
	unsigned short GetPort()const;

	std::string ValidDomainName(std::string const &domain);
	std::string ValidDocumentName(std::string const &domain);
	void ParseUrl(std::string const &url);
	Protocol CheckProtocol(boost::string_ref const &protocol, int &index) const;
	std::string ParseDomainName(boost::string_ref const &url, int &index);
	unsigned short ParsePort(boost::string_ref const &url, size_t index) const;
	int GetIndexStartDomainName(boost::string_ref const &url, int index = 0) const;

	std::string ToStringProtocol() const;
	std::string ToStringPort() const;

private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
