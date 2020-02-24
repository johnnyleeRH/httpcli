#ifndef HOBOT_HTTPCLI_H_
#define HOBOT_HTTPCLI_H_
#include <memory>
#include <sstream>
#include "ihttpcli.h"

namespace curlpp {
class Easy;
}
namespace hobot {
class IHttpCli;
class HttpCli : public IHttpCli {
 public:
  virtual int Send(const std::string& url, const std::string& content,
                   std::string& rsp);
  HttpCli(const HttpCli& rhs) = delete;

 public:
  HttpCli();

 private:
  std::shared_ptr<curlpp::Easy> request_;
  std::stringstream result_;
};

}  // namespace hobot

#endif  // HOBOT_HTTPCLI_H_
