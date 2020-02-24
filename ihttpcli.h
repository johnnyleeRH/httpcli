#ifndef HOBOT_IHTTPCLI_H_
#define HOBOT_IHTTPCLI_H_
#include <string>
namespace hobot {
class IHttpCli {
 public:
  virtual int Send(const std::string& url, const std::string& content,
                   std::string& rsp) = 0;
};
}  // namespace hobot
#endif