
#include "../../includes/push_swap.h"
#include "checker.h"

int ft_strcmp(char *str1, char *str2)
{
  if(!str1 || !str2)
    return (0);
  while(*str1 && *str2)
  {
    if(*str1 != *str2)
      return (int)*str1 - (int)*str2;
    str1++;
    str2++;
  }
  return (int)*str1 - (int)*str2;
}

void handle_instruction(char *inst, t_stack *a, t_stack *b)
{
  if(!ft_strcmp(inst, "sa\n"))
    swap(a, NULL);
  else if(ft_strcmp(inst, "sb\n"))
    swap(b, NULL);
  else if(!ft_strcmp(inst, "ss\n"))
  {
    swap(a, NULL);
    swap(b, NULL);
  }

  else if(!ft_strcmp(inst, "ra\n"))
    rotate(a, NULL);
  else if(ft_strcmp(inst, "rb\n"))
    rotate(b, NULL);
  else if(!ft_strcmp(inst, "rr\n"))
  {
    rotate(a, NULL);
    rotate(b, NULL);
  }

  else if(!ft_strcmp(inst, "rra\n"))
    reverse_rotate(a, NULL);
  else if(!ft_strcmp(inst, "rrb\n"))
    reverse_rotate(b, NULL);
  else if(!ft_strcmp(inst, "rrr\n"))
  {
    reverse_rotate(a, NULL);
    reverse_rotate(b, NULL);
  }
  
  else if(!ft_strcmp(inst, "pa\n"))
    push(b, a, NULL);
  else if(!ft_strcmp(inst, "pb\n"))
    push(a, b, NULL);
}

int sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->stack_size && a->stack[i] == a->metadata.sorted[i])
		i++;
	if (i == a->stack_size)
		return(1);
  return (0);
}


int main(int argc, char **argv)
{

  //(void)argv;
  //(void)argc;
  
  char *instruction;


  t_stack *a;
  t_stack *b;

  if(argc > 1)
  {
    if(!check_parameters(argc, argv)){
      exit(0);
    }
    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    a->stack = (int *)malloc(sizeof(int) * argc - 1);
    b->stack = (int *)malloc(sizeof(int) * argc - 1);
    a->stack_size = argc - 1;
    b->stack_size = 0;
    fill_stack(a, argc, argv);
    a->metadata.sorted = sort(a);
    // read instructions 
    
    print_stacks(a, b);
    instruction = get_next_line(0);
    while(instruction)
    {
      handle_instruction(instruction, a, b);
      printf("%s", instruction);
      free(instruction);
      instruction = get_next_line(0);
    }

    print_stacks(a, b);
    if(sorted(a))
      printf("OK\n");
    else
      printf("KO\n");
    
    //inp = (char *)malloc(sizeof(char) * 100);
    //read(0, inp, 100);
    //inp[99] = '\0';
    //printf("inp => %s", inp);
 
  }
   
  return (0);
}
