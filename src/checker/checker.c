
#include "../../includes/push_swap.h"
#include "checker.h"


int main(int argc, char **argv)
{

  //(void)argv;
  //(void)argc;
  //char *inp;

  printf("arg 1  : %s \n", argv[1]);

  if(argc > 1)
  {
    printf("nada !\n");
    if(!check_parameters(argc, argv)){
      printf("nada !\n");
      exit(0);
    }

    //inp = (char *)malloc(sizeof(char) * 100);
    //read(0, inp, 100);
    //inp[99] = '\0';
    //printf("inp => %s", inp);
 
  }
   
  return (0);
}
