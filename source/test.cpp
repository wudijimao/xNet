#include "HttpClient.h"
#include <fstream>
#include <iostream>
#include <curl/curl.h>
using namespace network;
void callback(HttpClient* client, HttpResponse* response) {
	std::vector<char> *data = response->getResponseData();
	std::fstream fs;
	fs.open("download.jpg", std::ios::out | std::ios::binary);
	fs.write(&((*data)[0]), data->size());
	fs.close();
	for (char a : *data) {
		std::cout << a;
	}
	char b;
	std::cin >> b;
}
void main() {
	curl_global_init(CURL_GLOBAL_WIN32);
	network::HttpRequest *request = new HttpRequest();;
	request->setUrl("http://img4q.duitang.com/uploads/item/201408/23/20140823214127_HK5UJ.jpeg");
	request->setRequestType(HttpRequest::Type::GET);
	request->setResponseCallback(&callback);
	HttpClient::getInstance()->send(request);
	Sleep(200000);
}