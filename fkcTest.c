#include "types.h"
#include "stat.h"
#include "user.h"

#define CHILD if (fork() == 0) exit()

int main()
{
  printf(1, "number of forks when program starts: %d\n", fkc(1));
  CHILD;
  CHILD;
  
  printf(1, "number of forks after two more forks: %d\n", fkc(1));

  wait();
  wait();

  fkc(0);
  printf(1, "number of forks after fork count cleared: %d\n", fkc(1));

  CHILD;
  CHILD;
  CHILD;
  wait();
  wait();
  wait();

  printf(1, "number of forks after three more forks: %d\n", fkc(12)); 

  exit();
}
