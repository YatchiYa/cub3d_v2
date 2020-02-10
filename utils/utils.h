
#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "../gnl/get_next_line.h"

# define PTR_CAST(a)	(void*)((uintptr_t)(a))
# define MAX(a, b)		((a > b) ? a : b)

typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct	s_str
{
	char			*content;
	struct s_str	*next;
}				t_str;


int				ft_in_set(char c, char const *set);

t_str			*str_new(void *content);

t_str			*str_add_back(t_str **str, char *content);

t_str			*str_last(t_str *str);

int				str_clear(t_str **list);

int				ft_strcmp(const char *s1, const char *s2);

int				ft_endwith(char const *str, char const *end);

#endif
