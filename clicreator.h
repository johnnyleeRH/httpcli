#ifndef CLI_CREATOR_H_
#define CLI_CREATOR_H_
#include "ihttpcli.h"

class CliCreator {
public:
static hobot::IHttpCli* CreateHttpCli();
};


#endif  // CLI_CREATOR_H_