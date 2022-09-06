#include "wrap.h"

#include <unistd.h>

int	wrap_dup2(int source_fd, int new_fd)
{
	return (dup2(source_fd, new_fd));
}
