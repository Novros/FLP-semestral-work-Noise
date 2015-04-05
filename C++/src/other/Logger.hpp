/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#pragma once
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * @file
 * @author  Rostislav Novak <rostislav.novak92@gmail.com>
 * @version 1.0
 *
 * @section LICENSE* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
**/

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// STL HEADERS
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
namespace rlib {
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
 * // TODO - vymyslet jak to udělat pouze na jednu instanci, aby všechny texty byly na stejný stream. Ale pozor na vícevláknové aplikace, aby to fungovalo.
*/
class Logger {
private:
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
	const std::string INFO_TAG = "[INFO]";
	const std::string ERROR_TAG = "[ERROR]";
	const std::string DEBUG_TAG = "[DEBUG]";

	// TODO Add option to set output.
	std::ostream *out_stream;
	std::ostream *error_stream;
	std::ostream *debug_stream;

	std::string TAG;

	bool writeTime = false;

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
public:
	/*********************************************** Constructors ****************************************************/
	Logger(const std::string & tag, const bool & writeTime = false) {
		this->writeTime = writeTime;
		TAG = "[" + tag + "]";

		std::stringbuf outputBuffer;
		out_stream = new std::ostream(&outputBuffer);		
		out_stream->rdbuf(std::cout.rdbuf());

		std::stringbuf debugBuffer;
		debug_stream = new std::ostream(&debugBuffer);		
		debug_stream->rdbuf(std::cout.rdbuf());

		std::stringbuf errorBuffer;
		error_stream = new std::ostream(&errorBuffer);		
		error_stream->rdbuf(std::cerr.rdbuf());
	}

	/************************************************* Setters *******************************************************/
	void setOutputStream(std::ostream & stream) {
		out_stream->rdbuf(stream.rdbuf());
		error_stream->rdbuf(stream.rdbuf());
		debug_stream->rdbuf(stream.rdbuf());
	}

	void setInfoStream(std::ostream & stream) {
		out_stream->rdbuf(stream.rdbuf());
	}

	void setErrorStream(std::ostream & stream) {
		error_stream->rdbuf(stream.rdbuf());
	}

	void setDebugStream(std::ostream & stream) {
		debug_stream->rdbuf(stream.rdbuf());
	}

	void resetStreams() {
		out_stream->rdbuf(std::cout.rdbuf());
		debug_stream->rdbuf(std::cout.rdbuf());
		error_stream->rdbuf(std::cerr.rdbuf());
	}

	/************************************************** Print *******************************************************/
	void print(const std::string & text) {
		*out_stream << text;
	}

	void print_line(const std::string & text) {
		*out_stream << text << std::endl;
	}

	void error_line(const std::string & text) {
		*error_stream << beforeTags() << ERROR_TAG << afterTags() << " " << text << std::endl;
	}

	void debug_line(const std::string & text) {
		*debug_stream << beforeTags() << DEBUG_TAG << afterTags() << " " << text << std::endl;
	}

	void info_line(const std::string & text) {
		*out_stream << beforeTags() << INFO_TAG << afterTags() << " " << text << std::endl;
	}

	/************************************************** Others *******************************************************/
	std::string beforeTags() const {
		return (this->writeTime ? getTimeString() : "");
	}

	std::string afterTags() const {
		return TAG;
	}

	std::string getTimeString() const {
		std::time_t time = std::time(nullptr);
		char buffer[100];
		std::strftime(buffer, sizeof(buffer), "[%Y-%m-%d][%H:%M:%S]", std::localtime(&time));
		std::string time_string = std::string(buffer);
		return time_string;
	}
};

}