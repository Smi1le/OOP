#pragma once
#include <string>

enum class Protocol
{
	HTTP,
	HTTPS
};




class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(std::string const &msg = std::string());
};