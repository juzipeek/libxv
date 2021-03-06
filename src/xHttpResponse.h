#pragma once

#include "all.h"

class xBuffer;
class xHttpResponse
{
public:
	enum HttpStatusCode
	{
		kUnknown,
		k2000k = 200,
		k301MovedPermanently = 301,
	};
	explicit xHttpResponse(bool close)
	:statusCode(kUnknown),
	 closeConnection(close)
	{

	}

	void setStatusCode(HttpStatusCode code)
	{
		statusCode = code;
	}

	void setStatusMessage(const std::string & message)
	{
		statusMessage = message;
	}

	void setCloseConnection(bool on)
	{
		closeConnection = on;
	}

	bool getCloseConnection()
	{
		return closeConnection;
	}

	void setContentTyoe(const std::string & contentType)
	{
		addHeader("Content-Type", contentType);
	}

	void addHeader(const std::string &key,const std::string &value)
	{
		headers[key] = value;
	}

	void setBody(const std::string &body )
	{
		this->body = body;
	}

	void appendToBuffer(xBuffer* output) const;


private:
	std::map<std::string,std::string> headers;
	HttpStatusCode statusCode;
	std::string statusMessage;
	bool closeConnection;
	std::string body;
};
