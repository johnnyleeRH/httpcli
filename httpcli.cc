#include "httpcli.h"
#include <curlpp/curlpp/Easy.hpp>
#include <curlpp/curlpp/Exception.hpp>
#include <curlpp/curlpp/Options.hpp>
#include <curlpp/curlpp/cURLpp.hpp>

namespace hobot {
HttpCli::HttpCli() {
  request_.reset(new curlpp::Easy);
  curlpp::OptionTrait<bool, CURLOPT_SSL_VERIFYPEER> sslVerifyPeer(false);
  curlpp::OptionTrait<bool, CURLOPT_SSL_VERIFYHOST> sslVerifyHost(false);
  request_->setOpt(new curlpp::options::Verbose(false));

  std::list<std::string> header;
  header.push_back("Content-Type: application/json");
  request_->setOpt(sslVerifyPeer);
  request_->setOpt(sslVerifyHost);
  request_->setOpt(new curlpp::options::HttpHeader(header));
  request_->setOpt(new curlpp::options::Timeout(5));
  request_->setOpt(new curlpp::options::NoSignal(true));
  request_->setOpt(cURLpp::Options::WriteStream(&result_));
}

int HttpCli::Send(const std::string& url, const std::string& content, std::string& rsp) {
  try {
    result_.str("");
    result_.clear();
    request_->setOpt(new curlpp::options::Url(url.c_str()));
    request_->setOpt(new curlpp::options::PostFields(content));
    request_->setOpt(new curlpp::options::PostFieldSize(content.length()));
    request_->perform();
  } catch (curlpp::LogicError &e) {
    std::cout << e.what() << std::endl;
    return -1;
  } catch (curlpp::RuntimeError &e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
  rsp = result_.str();
  return 0;
}

}