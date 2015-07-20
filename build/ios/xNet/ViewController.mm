//
//  ViewController.m
//  xNet
//
//  Created by ximiao on 15/7/20.
//  Copyright (c) 2015年 ximiao. All rights reserved.
//

#import "ViewController.h"
#include "HttpClient.h"
#include <fstream>
#include <iostream>
using namespace network;

static std::string str;

void callback(HttpClient* client, HttpResponse* response) {
    std::vector<char> *data = response->getResponseData();
    std::fstream fs;
    fs.open(str, std::ios::out | std::ios::binary);
    if (fs.is_open()) {
        fs.write(&((*data)[0]), data->size());
        fs.close();
        std::cout << "成功";
    } else {
        std::cout << "失败";
    }
}
int downloadimgeTest() {
    network::HttpRequest *request = new HttpRequest();;
    request->setUrl("http://img4q.duitang.com/uploads/item/201408/23/20140823214127_HK5UJ.jpeg");
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback(&callback);
    HttpClient::getInstance()->send(request);
    //sleep(200000);
    return 0;
}

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString *cachesDir = [paths objectAtIndex:0];
    NSString *savePath = [NSString stringWithFormat:@"%@/download12345.jpg", cachesDir];
    str = [savePath cStringUsingEncoding:NSUTF8StringEncoding];
    // Do any additional setup after loading the view, typically from a nib.
    downloadimgeTest();
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
