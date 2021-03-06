#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

/*

Osmium -- OpenStreetMap data manipulation command line tool
http://osmcode.org/osmium

Copyright (C) 2013-2016  Jochen Topf <jochen@topf.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <stdexcept>

/**
 *  Thrown when there is a problem with the command line arguments.
 */
struct argument_error : std::runtime_error {

    explicit argument_error(const char* message) :
        std::runtime_error(message) {
    }

    explicit argument_error(const std::string& message) :
        std::runtime_error(message) {
    }

};


#endif // EXCEPTION_HPP
