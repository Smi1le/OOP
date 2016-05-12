#pragma once
#include "UrlParsingError.h"
#include <boost/utility/string_ref.hpp>
#include <iostream>


class CHttpUrl
{
public:
	// выполн€ет парсинг строкового представлени€ URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(std::string const& url);

	/* инициализирует URL на основе переданных параметров.
	ѕри недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	≈сли им€ документа не начинаетс€ с символа /, то добавл€ет / к имени документа
	*/
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP,
		unsigned short port = 80u);

	// возвращает строковое представление URL-а. ѕорт, €вл€ющийс€ стандартным дл€
	// выбранного протокола (80 дл€ http и 443 дл€ https) в URL не должен включатьс€
	std::string GetURL()const;

	// возвращает доменное им€
	std::string GetDomain()const;

	/*
	¬озвращает им€ документа. ѕримеры:
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
