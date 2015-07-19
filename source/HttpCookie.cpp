/****************************************************************************
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HttpCookie.h"
#include <sstream>
#include <stdio.h>

void HttpCookie::readFile()
{
   
}

const std::vector<CookiesInfo>* HttpCookie::getCookies() const
{
    return &_cookies;
}

const CookiesInfo* HttpCookie::getMatchCookie(const std::string& url) const
{
    for(auto iter = _cookies.begin(); iter != _cookies.end(); iter++)
    {
        if(url.find(iter->domain) != std::string::npos)
            return &(*iter);
    }
    
    return nullptr;
}

void HttpCookie::updateOrAddCookie(CookiesInfo* cookie)
{
    for(auto iter = _cookies.begin(); iter != _cookies.end(); iter++)
    {
        if(cookie->domain == iter->domain)
        {
            *iter = *cookie;
            return;
        }
    }
    _cookies.push_back(*cookie);
}

void HttpCookie::writeFile()
{

}

void HttpCookie::setCookieFileName(std::string filename)
{
    _cookieFileName = filename;
}
