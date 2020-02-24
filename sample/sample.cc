#include <iostream>
#include <memory>
#include <string>
#include "clicreator.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
using namespace rapidjson;
using rapidjson::Document;
using rapidjson::StringBuffer;
using rapidjson::StringRef;
using rapidjson::Writer;

/*
image query example:
{
'config': {
'action': 'get_reqt',
'module': [{
  'name': 'image'
}]
}
}
*/

void GetReq(std::string& req) {
  Document doc;
  Document::AllocatorType& allocator = doc.GetAllocator();
  rapidjson::Value config(rapidjson::kObjectType);
  config.AddMember("action", StringRef("get_reqt"), allocator);
  rapidjson::Value modulename(rapidjson::kObjectType);
  modulename.AddMember("name", "image", allocator);
  rapidjson::Value module(rapidjson::kArrayType);
  module.PushBack(modulename, allocator);
  config.AddMember("module", module, allocator);
  rapidjson::Value root(rapidjson::kObjectType);
  root.AddMember("config", config, allocator);
  StringBuffer buffer;
  Writer<StringBuffer> propertiesWrite(buffer);
  root.Accept(propertiesWrite);
  req = buffer.GetString();
  std::cout << req << std::endl;
}

int main() {
  std::shared_ptr<hobot::IHttpCli> httpcli(CliCreator::CreateHttpCli());
  std::string url = "http://127.0.0.1:8089/common/config";
  std::string content;
  GetReq(content);
  std::string rsp;
  if (0 == httpcli->Send(url, content, rsp))
    std::cout << rsp << std::endl;
}