#include "clicreator.h"
#include "httpcli.h"

hobot::IHttpCli* CliCreator::CreateHttpCli() {
  return new hobot::HttpCli();
}