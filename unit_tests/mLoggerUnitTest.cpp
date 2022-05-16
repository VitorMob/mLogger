#include "../src/include/mlogger.hpp"


int main()
{
  mLogger log("test.log");

  log.mlogger_warning("Fail in create name");
  log.mlogger_information("Created user");

}
