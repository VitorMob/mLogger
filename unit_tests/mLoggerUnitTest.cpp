#include "../src/include/mlogger.hpp"

int main()
{
  mLogger log("test.log", 1025, true);

  log.mlogger_warning("Fail in create name ");
  log.mlogger_information("Created user ");
  log.mlogger_about("Created user ");
  log.mlogger_error("Not created user ");
}